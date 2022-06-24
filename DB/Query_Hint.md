# STUDY
always study🧑‍💻🧑‍💻

## DB 운영에서 필요한 지식 - 힌트
## Query를 사용할 때 원하는 방향(최적화)으로 쿼리를 실행시키기 위해 힌트를 사용

## QUERY_TRANSFORMATION - TRANS
  + NO_QUERY_TRANSFORMATION
    + default로 수행되는 쿼리 변형을 막을 수 있다.
    + ```/*+ NO_QEURY_TRANSFORMATION*/```
  + NO_MERGE
    + default로 진행되는  view merge를 막는다.
    + ```/*+ NO_MERGE*/```
  + UNNEST
    + subquery의 블럭에 명시
    + ```/*+UNNEST*/```
  + NO_UNNEST
    + subquery에 명시
    + ```/*+ NO_UNNEST*/```
  + NO_JOIN_ELIMINATION
      + 불필요한 조인을 찾아서 제거하는 기능을 막기
       ```
      + /*+ NO_JOIN_ELIMINATION*/
      + select /*+ NO_JOIN_ELIMINATION*/ [T2.FK](http://T2.FK), T2.A from T1, T2 where T2.FK = T1.PK;
       ```
  + STAR_TRANSFORMATION
    + star tranformation 이 가능할 경우 변형을 시도하도록 지시하는 힌트
    + ```/*+ STAR_TRANSFORMATION*/  S.* from S, T1, T2 where S.C1 = T1.C1 AND S.C2=T2.C2;```
    + star 변형 ⇒ 이 변형은 기존 INDEX JOIN 으로만 풀린 플랜에서 BITMAP KEY ITERATION을 포함한 플랜으로 플리게 하여 더 효율적인 결과를 얻게 한다.
## 최적화 방법 - OPTIMIZER
  + optimizer가 적용된 힌트를 사용하여 **처리 과정과 결과 표시**를 최적화할 수 있다. 만일 최적화 방법이 적용된 힌트가 사용된 query가 있다면 해당 query에 대해서는 통계정보와 초기화 파라미터의 최적화 방법이 없는 것처럼 처리된다.
  + ALL_ROWS
    + 최소한의 리소스를 사용하여 전체 결과에 대한 처리량이 가장 많도록 처리과정의 최적화 방법을 선택하는 힌트
    + ```/*+ ALL_ROWS*/```
  + FIRST_ROWS
    + 첫 row부터 파라미터로 입력된 번호의 row가지 가장 빠르게 보여줄 수 있도록 결과 표시의 최적화 방법을 선택하는 힌트
    + ```/*+ FIRST_ROWS( integer ) */```
## 접근 방법 - ACCESS
  + 접근 방법이 적용된 힌트는 query의 optimizer가 특정 접근방법의 사용이 가능한 경우, 그 방법을 사용하도록 명시한다.
  + 힌트에 명시하는 테이블명은 SQL문에서 사용하는 이름과 동일해야 한다. 즉, 테이블 이름에 대한 별칭을 하용하였다면, 이름 대신에 별칭을 사용하여야 한다.
  + SQL문에서 테이블 이름에 스키마 이름을 포함하여 명시하였더라도 힌트에서는 테이블 이름만을 명시하여야 한다.
  + FULL
    + 명시한 테이블을 스캔할 때, 전체 테이블을 스캔하도록 지시하는 힌트이다.
    + where절에 명시된 조건식에 맞는 인덱스가 있더라도 전체 테이블 스캔을 사용한다.
    + ```/*+ FULL(tablespec)*/```
    + ```select /*+FULL(T1)*/ * from T1;```
  + INDEX
    + 명시한 테이블을 스캔할 때, 명시한 인덱스를 사용하여 인덱스 스캔을 하도록 지시하는 힌트.
    + ```/*+ INDEX(tablespec→indexspec) */```
    + ```select /*+INDEX(T1 T1_INDEX)*/ * from T1;```
  + NO_INDEX
    + 명시한 테이블을 스캔할 때, 명시한 인덱스를 사용하는 인덱스 스캔을 하지 않도록 지시하는 힌트이다. 만일 NO_INDEX 힌트와 INDEX 또는 INDEX_ASC, INDEX_DESC 힌트가 동일한 인덱스를 명시한다면 나머지 두 힌트를 모두 무시
    + ```/*+ NO_INDEX(tablespec→indexspec)*/```
  + INDEX_ASC
    + Tibero의 인덱스 스캔의 기본 동작이 오름차순이기 때문에 INDEX_ASC는 INDEX와 동일한 작업을 수행한다.
    + 범위 스캔을 사용하는 경우에는 인덱스를 오름차순으로 스캔하도록 한다.
    + 분할된 인덱스의 경우 분할된 각 영역 내에서 오름차순으로 스캔한다.
    + ```/*+ INDEX_ASC(tablespec→indexspec)*/```
  + INDEX_DESC
    + ```/*+INDEX_DESC(tablespec→indexspec)*/```
  + INDEX_FFS
    + ```/*+ INDEX_FFS(tablespec→indexspec)*/```
    + index fast full scan
  + NO_INDEX_FFS
  + INDEX_RS
    + 명시한 테이블에 대해 명시한 인덱스를 사용하여 범위 인덱스 스캔(Range Index Scan)을 사용하도록 지시하는 힌트.
    + ```/*+ INDEX_RS(tablespec→indexspec)*/```
  + NO_INDEX_RS
  + INDEX_SS
    + ```/*+ INDEX_SS(tablespec→indexspec)*/```
    + index skip scan
  + NO_INDEX_SS
    + ```/*+ NO_INDEX_SS(tablespec→indexspec)*/```
  + INDEX_JOIN
    + 명시한 테이블에 대해 명시한 두 개 이상의 힌트를 사용하여(?), 테이블을 스캔할 때 self join을 사용하도록 지시하는 힌트.

## JOIN 순서
  + Leading, Ordered는 조인 순서를 결정하는 힌트이다. Leading 힌트가 Ordered보다 Query Optimizer를 선택할 수 있는 폭이 넓어서 Leading을 사용하는 것이 좋다.
  + LEADING
    + 조인에서 먼저 조인되어야 할 테이블의 집합을 명시하는 힌트.
    + Leading 힌트가 먼저 조인될 수 없는 테이블을 포함하는 경우 무시한다.
    + Leading 힌트끼리 충돌하는 경우에는 Leading, Ordered 힌트가 모두 무시된다.
    + Ordered 힌트가 사용되는 경우에는 Leading 힌트는 모두 무시된다.
## 조인 방법
  + 한 테이블에 대해서만 조인 방법을 지시한다.
  + 조인 방법이 적용된 힌트는 명시한 테이블이 **조인의 내부 테이블**로 사용될 경우에만 참조된다.
  + USE_NL
    + 명시한 테이블을 다른 테이블과 조인하는 경우 Nested Loop Join을 사용하도록 지시
    + ```/*+ USE_NL(tablespec)*/```
  + NO_USE_NL
    + ```/*+NO_USE_NL(tablespec)*/```
  + USE_NL_WITH_INDEX
    + 명시한 테이블을 다른 테이블과 조인하는 경우 중첩 루프 조인을 사용하도록 지시하는 힌트.
    + 이때 명시한 테이블에 대한 접근은 명시한 인덱스와 두 테이블에 대한 조인 조건을 이용하여 이루어져야 한다.
    + 인덱스를 사용하는 경우이면 힌트는 무시
    + ```/*+ USE_NL_WITH_INDEX(tablespec indexspec)*/```
  + USE_MERGE
    + MERGE JOIN을 유도
    + ```/*+ USE_MERGE(tablespec)*/```
  + NO_USE_MERGE
    + ```/*+NO_USE_MERGE(tablespec)*/```
  + USE_HASH
    + 명시한 테이블을 다른 테이블과 조인하는 경우 해시 조인을 사용하도록 지시하는 힌트
    + ```/*+ USE_HASH(tablespec)*/```
  + NO_USE_HASH
    + ```/*+ NO_USE_HASH(tablespec)*/```
  + subquery unnest
    + HASH_SJ
      + subquery를 unnesting할 때 해시방법을 이용한 세미조인으로 하도록 지시하는 힌트
      + ```/*+ HASH_SJ*/```
    + HASH_AJ
      + subquery를 unnesting 할 때 HASH방법을 이용한 anti join으로 하도록 지시하는 힌트
      + ```/*+HASH_AJ*/```
    + MERGE_SJ
      + subquery를 unnesting할 때 Merge 방법을 이용한 semi join하도록 지시하는 힌트
      + ```/*+ MERGE_SJ*/```
    + MERGE_AJ
      + subquery를 unneest할 때 Merge방법을 이용한 Anti Join하도록 지시하는 힌트
      + ```/*+ MERGE_AJ*/```
    + NL_SJ
      + ```/*+NL_SJ*/```
    + NL_AJ
      + ```/*+ NL_AJ*/```
  + SWAP_JOIN_INPUTS
    + Hash Join을 수행하는 경우 명시한 테이블을 사용하여 Hash Table을 빌드하도록 지시하는 힌트
    + ```/*+ SWAP_JOIN_INPUTS(tablespec)*/```
  + NO_ SWAP_JOIN_INPUTS
    + Hash Join을 수행하는 경우 Join 순서가 바뀌는 경우, 명시한 테이블이 해시 테이블로 빌드되지 않도록 지시하는 힌트
    + ```/*+ NO_SWAP_JOIN_INPUTS(tablespec)*/```
## PARALLEL
  + 병렬 쿼리는 **divide & conquer** 원리에 기초한다.
  + PARALLEL
    + 지정한 개수의 스레드를 사용해 query 수행을 병렬로 진행
    + ```/*+ PARALLEL(integer)*/```
  + NO_PARALLEL
    + ```/*+ NO_PARALLEL*/```
  + PQ_DISTRIBUTE
    + 병렬 조인은 **분배와 조인(Distribute & Join)**으로 진행된다.
    + PQ_DISTRIBUTE 힌트는 JOIN 전에 분배하는 과정에만 관여하는 힌트
    + 조인되는 두 테이블간의 파티션의 구성, 데이터 크기에 따라 병렬 조인을 수행하는 옵티마이져의 선택이 달라질 수 있다.
    + 이 때 사용자가 직접 조인을 위한 데이터 분배 방식을 결정 할 수 있는 힌트.
      + 사용 목적
      + 옵티마이져가 파티션된 테이블을 적절히 활용하지 못하고 동적 재분할을 시도할 때
      + 기존 파티션 키를 무시하고 다른 키 값으로 동작 재분할하고 싶을 때
      + 통계정보가 부정확하거나 통계정보를 제공하기 어려운 상황에서 실행계획을 고정시고정시 할 때
      + 기타 여러 가지 이유로 데이터 분배 방식을 변경하고 자 할 때
    + ```/*+ PQ_DISTRIBUTTE(tablespec HASH HASH)*/```
      + BROADCAST NONE ⇒ 왼쪽은 BROADCAST 오른쪽은 PE BLOCK ITERATOR의 분산 방법으로 동작
      + NONE BROADCAST ⇒ 왼쪽 pe block iterator 오른쪽 broadcast
      + NONE NONE ⇒ 양쪽 모두 Hash의 분산 방법으로 동작
    + ```/*+ pq_distribute(table, outer_distribution, inner_distribution)*/```
      + table - inner table 명
      + outer table의 distribute 방식
      + inner table의 distribute 방식
