# STUDY
always study

## DB 운영에서 필요한 지식 - 힌트
## Query를 사용할 때 원하는 방향(최적화)으로 쿼리를 실행시키기 위해 힌트를 사용

## QUERY_TRANSFORMATION - TRANS
  + NO_QUERY_TRANSFORMATION
    + default로 수행되는 쿼리 변형을 막을 수 있다.
    + /*+ NO_QEURY_TRANSFORMATION*/
  + NO_MERGE
    + default로 진행되는  view merge를 막는다.
    + /*+ NO_MERGE*/
  + UNNEST
    + subquery의 블럭에 명시
    + /*+UNNEST*
  + NO_UNNEST
    + subquery에 명시
    + /*+ NO_UNNEST*
  + NO_JOIN_ELIMINATION
      + 불필요한 조인을 찾아서 제거하는 기능을 막기
      + /*+ NO_JOIN_ELIMINATION*/
      + select /*+ NO_JOIN_ELIMINATION*/ [T2.FK](http://T2.FK), T2.A from T1, T2 where T2.FK = T1.PK;
  + STAR_TRANSFORMATION
    + star tranformation 이 가능할 경우 변형을 시도하도록 지시하는 힌트
    + /*+ STAR_TRANSFORMATION*/  S.* from S, T1, T2 where S.C1 = T1.C1 AND S.C2=T2.C2;
    + star 변형 ⇒ 이 변형은 기존 INDEX JOIN 으로만 풀린 플랜에서 BITMAP KEY ITERATION을 포함한 플랜으로 플리게 하여 더 효율적인 결과를 얻게 한다.
