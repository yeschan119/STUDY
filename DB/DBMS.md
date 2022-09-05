** DBMS 개요
<H2>1. Join</H2>
* Nested Loop Join
  <strong><em>old classic join</em></strong>
  1. optimizer가 먼저 수행될 outer 집합을 결정한다. 이것을 선행(driving)집합이라고 한다. 선행집합의 각 row에 대해 inner 집합을 연결하게 된다.
  2. Driving 집합이 액세스되면 그들의 모든 컬럼은 상수값을 가진다.
  3. 실제로 Join이 수행될 때는 outer 집합의 각각의 row에 대해 inner 집합의 대응되는 모든 row가 액세스된다.
  * <strong>Nested Loops Join은 랜덤 액세스를 진행하므로 Join의 대상 범위가 넓거나, 마땅한 인덱스가 존재하지 않을 때에는 성능에 영향을 미친다.</strong>
* Sort Merge Join
  <strong><em>Nested Loops Join이 가진 문제를 해결하기 위한 일종의 대안.</em></strong>
  1. 가장 큰 특징은 랜덤 액세스를 하지 않고 스캔을 하면서 이를 수행한다는 것.
  2. 1번을 수행하기 위해서는 먼저 Join은 대상들을 정렬해야 한다.
  3. 만일 정렬이 메모리내에서 이루어질 수 있는 사이즈라면 상당히 빠른 수행속도를 보장한다.
  * <strong>그럼에도 불구하고 대용량 데이터에서는 정렬 자체가 Nested Loops Join보다 더 성능을 떨어뜨릴 수 있다.</strong>
* Hash Join
  <strong><em>정렬을 하지 않고 연결할 대상들을 주변에 위치시킬 수 있는 방법이다.</em></strong>
  1. Hashing 기법을 사용해서 Join을 수행하는 방식이다.
  2. Hashing함수는 컬럼의 값을 받아서 row의 저장위치를 리턴한다.
  3. Hashing함수는 두 집합을 직접적으로 연결하는 것이 아니라 연결되는 대상을 특정 위치에 모아두는 역할만 한다.
  4. 이렇게 동일한 해쉬값을 가진 데이터들을 모아둔 공간을 <em>Partition</em>이라고 하고 이들을 이용하여 하는 Join을 <em>Partition Pair</em>라고 부른다.
  * <strong>Hash Join은 <em>Equijoin</em>일 때만 가능하므로 제약이 있다.</strong>

<H2>2. Subqueries</H2>
* inline view
  Subquery는 WHERE, FROM, SELECT 어느 절이든 다 들어갈 수 있는데, 특히 FROM 절에 들어가는 Subqury를 inline view라고 한다.
* Scalar Subquery
  1. 주로 SELECT 절에서 사용하는 Subquery로 한개의 row만 반환한다.
  2. Main query에서 추출되는 데이터 건 수 만큼 수행되기 때문에 Join으로 수행 될 때보다 수행회수가 적을 수 있다.
  3. 코드성 테이블에서 코드값을 조회 할 때, 불필요한 조인을 하지 않기 위해 많이 사용한다
  4. 일치하는 값이 없을 경우 NULL을 반환한다.
  * Select * from (select A from Test) where A=1;
<H2>3. Analytic Function(분석 함수)</H2>
  1. Aggregate Function의 계산을 진행할 때 한 그룹에 대해 여러 row가 출력되게 한다. 이때 row들의 그룹을 window라고 한다.
  2. Analytic Function은 WHERE, Having, Group by와 같이 쓰일 때 가장 마지막에 연산을 진행한다.
  3. Over절을 통해 사용할 수 잇다.
  4. Over(Partition by column)은 컬럼값이 같은 애들끼리 수행하라는 의미.
  * Select name, team, score , avg(score) over(partitoin by team) team_avg from grade;
    <strong>이렇게 group by를 사용하지 않고 over를 이용해서 그룹을 만들 수 있다.</strong>
  5. Analytic functions
   > Aggregation(sum, max, min, avg, count)
   > Ranking(rank, dense_rank, row_number)
   > Ordering(First_Value, Last_Value, Lag, Lead)
   > Group내 비율(Cume_dist, Percent_Rank, NTile, ...)
   > Linear분석을 포함한 통계 함수(Corr, Covar_pop, Covar_Samp, Stddev, Stddev_pop, variance, ...)
<H2>4. Transaction(Isolation Level)</H2>
  <strong><em>동시에 여러 트랜잭션이 처리될 때 특정 트랜잭션이 다른 트랜잭션에서 변경하거나 조회하는 데이터를 볼 수 있도록 허용할지 말지를 결정하는 것</em></strong>
* Read Uncommitted
  > 각 트랜잭션에서의 변경 내용이 commit이나 rollback여부에 상관 없이 다른 트랜잭션에서 값을 읽을 수 있다.
  > Consistency에서 문제가 많은 isolation level이기 때문에 사용하지 않는 것을 권장.
  > <strong>Dirty Read현상 발생(트랜잭션 작업이 완료되지 않았는데도 다른 트랜잭션에서 볼 수 있게 되는 현상</strong>
* Read Commited
  > RDB에서 기본적으로 사용되고 있는 level이다.
  > 실제 테이블값을 가져오는 것이 아니라 Undo영역의 백업된 레코드에서 값을 가져온다.
  > Dirty Read 현상은 발생하지 않는다.
  > <strong> non repeatable read 발생. 즉, 한 번 봤던 row가 다음 조회에서 안보이거나 변경되어 보일 수 있다.</strong>
* Repeatable Read
  > MySQL에서는 트랜잭션마다 ID를 부여하여 트랜잭션 ID보다 작은 번호에서 변경한 것만 읽게 된다.
  > Undo공간에 백업해두고 실제 레코드 값을 변경한다.
  > 이러한 방식을 MVCC(Multi Version Concurrency Control)이라고 한다.
  > <strong>Phantom Read 발생. 즉 동일 query를 재수행 하였을 때 첫 번째 조회에서 안보이던 row가 두번째에서는 갑자기 보이게 되는 현상</strong>
* Serializable
  > 가장 단순한 격리 수준이지만 가장 엄격한 격리 수준
  > 성능 측면에서 동시 처리성능이 가장 낮다.
  > 완벽한 isolation level이지만 데이터베이스에서 거의 사용되지 않는다.
<H2>더 봐야 할 내용<H2>
* Index range scan & RowID scan
* DBLink
* PL/SQL, SQL/PSM
