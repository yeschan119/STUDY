1. DBMS 개요
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
2. Tibero structure 개요

<H2>Process & Thread</H2>

* <strong>Foreground Process</strong>
  1. <em>Worker Process</em>
   - 이름 : <strong>tbsvr_FGWP</strong>
   - Client의 요청(Query)을 처리하는 process
   - DB에서 가장 많은 일을 하는 process
   - 다수의 thread(worker thread)를 보유하고 session(client 연결)과 worker process의 thread가 일대일로 대응

  2. <em>Control Thread(CTHR)</em>
   - process 및 thread들을 관리
    + 다른 프로세스와 통신을 하거나 monitor process의 명령을 처리
    + connection이 들어오거나 끊기면 worker thread할당 및 kill
    + statement cancel요청을 받아서 worker thread cancel

  3. <em>Manager Process</em>
   - 이름 : <strong>tbsvr_MGWP</strong>
   - 관리자 전용 worker process
   - Sys계정으로만 접속 가능하며, 별도의 Port(special port)로 접속
   - Session Full등 사용자 worker process가 접속 불가할 때 이용

  4. <em>Parallel Execution Process</em>
   - 이름 : <strong>tbsvr_PEWP</strong>
   - worker process와 같은 구조를 가지고 다수의 worker thread로 parallel execution을 전담
   - parallel이 포함된 sql당 하나의 PEWP가 지정된다.
   - PE coordinator(worker process의 session)의 지시를 받아 parallel 수행

* <strong>Background Process</strong>
  1. <em>Listener</em>
   - name : <strong>tblistener</strong>
   - client의 TCP connection을 받아서, 가용 세션이 있는 process에 전달.
   - tblistener는 monitor process가 생성하고, 죽으면 또 생성.
   - 특정 포트를 추가로 더 listen할 수 있다.

  2. <em>Monitor Process</em>
   - name : <strong>tbsvr</strong>
   - instance 전체 프로세스의 부모역할을 하는 프로세스. 즉, 하위의 모든 프로세스를 생성.
   - 단 하나의 thread만 존재
   - 자식 프로세스들의 종료 감지 및 복구 관리, listener 관리, 내부 로지컬 시계인 system tick 관리.

  3. <em>Agent Process</em>
   - name : <strong>tbsvr_AGNT</strong>
   - Background job등을 관리하거나 보조
   - Threads
    + Agent : 주기적으로 수행해야 하는 internal task(deadlock, index coalesce...)들을 수행.
    + Scheduler
    + NTFC : Pub/Sub의 Notification Coordinator
    + NTFS : Pub/Sub의 Notification Sender
    + TPR : Tibero Performance Repository 정보 저장 및 관리
    + Activity Monitor : 비정상적인 thread를 감지하여 debugging log.
    + TPM Collector, TPM Senter, Callstack Manager...

  4. <em>DB Writer Process</em>
   - name : <strong>tbsvr_DBWR</strong>
   - DB Block과 Redo log등을 쓰는 프로세스
   - Threads
    + LGWR : Log Writer
    + LGWRS : Log Writer Slave(AIO모드로 동작할 때)
    + LARC : Log Archiver(switch된 redo log를 담당)
    + CRPT : Checkpointer (Buffer Cache의 checkpoint 관리)
    + BLKW : Block Writer (Buffer cache의 dirty block들을 파일에 쓰기
    + LNW : Log Network Writer (Standby Cluster 구성에서 redo log를 전송)
    + BCT : Block Change Tracker (Backup 이후 변경된 블럭들을 추적해서 logging)
    + FBWR : Flashback writer (Flashback 기능을 위해 관련 정보를 write)
    + FARC : Flashback archiver (Flashback 관련 정보를 archive)

  5. <em>Recovery Process</em>
   - name : <strong>tbsvr_RCWP</strong>
   - Recovery jobs
    + DB Recovery(TAC, Media, Parallel, Transaction)
    + TSC(Standby Cluster)관련 작업

  6. <em>Active Cluster Daemon Process</em>
   - name : <strong>tbsvr_ACSD</strong>
   - TAC를 서비스하기 위한 프로세스
   - 역할
    + Cluster Reconfiguration : Node 구성이 변경되었을 때 재구성 담당
    + Cluster Message Service : Node간 message 송/수신 처리 담당
    + Global Cache Service : Global Buffer Cache관련 정보를 관리
    + Diagnosis : hang 의심 현상 발생 시 관련 정보를 dump
  
  7. <em>Storage Server I/O Process</em>
   - name : <strong>tbsvr_SSIO</strong>
   - Storage Server와 통신 및 통신채널을 관리하기 위한 프로세스
   - Threads
    + SSIO CTHR : TCP통신일 때 msg전송 담당
    + IBEM : Storage Server와 IB(Infiniband)통신을 관리하기 위한 msg들을 처리.

  8. <em>Storage Server Process</em>
   - name : <strong>tbsvr_SSVR</strong>
   - ZetaData에서 Storage Server instance에 생성되는 프로세스
   - Threads
    + DB, TAS 요청 처리
    + I/O 완료 처리
    + Infiniband 관리
    + Flash Cache 관리

<H2>Communication</H2>

* <strong>Server Communication Channel</strong>
  1. TCP
  2. Infiniband
   <em>ZetaData에서 Storage Server와 통신시 data를 주고 받는 용도로 사용</em>
   - RDMA(Remote Direct Memory Access)전용 API 사용
   - 별도의 Infiniband 장비가 필요.
* <strong>Inter Process Communication(IPC)</strong>
  1. Bitqueue
   <em>두 thread 사이 통신을 하기 위해 Tibero가 구현한 IPC mechanism.</em>
   - API가 심플하고 추가 메모리가 필요하지 않음.
   - 어떤 event인지(bit on)에 대해서만 전달이 가능하고, 데이터는 전달 불가.
   - semaphore + Bit array(Shared memory) + spinlock으로 구현
   - bitq_read(bitmask, timeout), bitq_write(sessid, msgbit)

  2. Pipe
   <em>특정 프로세스에 메시지를 보내기 위한 통신에 사용</em>
   - 요청과 함께 일부 데이터를 함께 보낼 수 있음
   - booting시 Monitor Process가 모든 process용 Pipe를 생성한 다음 child process를 fork 한다.
   - svr_sendmsg(target_process_index, msg_type, data..)
   - stchr_recv_from_pipe()

  3. Signal
   <em>User용 signal 통신 용도로 사용</em>
   - 어디가 수행되든 async하게 signal handler를 수행하게 할 수 있음.
   - System call 중이었을 때, 수행이 지연되는 케이스가 있음
   - tb_thread_kill(sessid, tibero_signal_type)

<H2>Memory</H2>

* <strong>Shared Memory</strong>
  <em>모든 프로세스가 공유하는 memory
  System V 방식 공유메모리 사용되고 사용 목적에 따라 여러 영역으로 구분해서 사용
  SGA(System Global Area)라고도 불림(Oracle)</em>

  1. Fixed Memory
   - Booting시 DB에서 사용할 각종 자료구조들이 할당되는 영역
   - Session과 thread 들의 정보들을 할당
   - Buffer Cache의 자료구조나 redo log buffer(LOG_BUFFER)도 여기서 할당

  2. Buffer Cache
   - Fixed Memory의 일종
   - 데이터 파일을 블록 단위로 cache.
   - Booting 시 미리 크게 할당 (DB_CACHE_SIZE)

  3. Shared Pool
   - Booting이후 동적으로 할당하여 사용.
   - 4가지 영역
    + LC : Library Cache로 PP(Physical Plan)정보를 저장하는 공간
    + DD : Data Dictionary cache 공간
    + SLAB : 동적으로 자주 할당 및 해제되는 구조체들의 할당 공간
    + MISC : 그 외 자유롭게 사용하는 shared memory 공간.

* <strong>Process Memory</strong>
   <em>각 프로세스 내에서 사용하는 Memory.
   Session이 SQL 수행 중 runtime에 필요한 메모리 할당 시 사용.
   Background Process에서도 수행 로직에 따라 공간 할단. PGA(Process Global Area)라고 불림(Oracle)</em>

  1. System Memory
   - I/O나 Background에서 사용하는 메모리
   - 각 Thread들이 사용하는 자료구조 등 할당

  2. Session Memory
   - Session의 runtime 동적 할당 메모리

  3. Statement Memory
   - SQL statement 단위로 사용하는 메모리

  4. Execution Memory
   - Executor가 SQL시 사용하는 메모리
   - Process Memory 중 가장 많은 공간을 사용
   - Sort, Hash 등 연산이나 중간 결과 저장에 사용

  5. Message Memory
   - 메시지 송/수신을 위한 메모리

<H2>Lock</H2>
  <em>Tibero Locks : AOP, Spinlock, RWLock, WLock, CWS Lock</em>
* <strong>AOP LOCK(Atomic Operation Lock)</strong>
  1. Lock을 획득하기 위해 Lock변수에 atomic operation을 계속 시도하면서 획득하는 방식.
  2. Lock을 획득할 때까지 계속해서 CPU를 소모.
  3. Critical Section이 아주 짧은 구간일 때만 사용. 튜닝 불가.
  * <em>Lock을 획득한 thread가 비정상 종료하면 해당 lock은 회복 불가(hang 발생)</em>

* <strong>Spinlock</strong>
  1. Lock을 획득하기 위해 Lock변수에 atomic operation과 normal operation, sleep을 적절히 사용하면서 획득하는 방식.
  2. AOP lock에 비해 CPU를 덜 사용.
  3. Blocking이 발생하지 않는 로직 구간을 보호할 때 사용.
  4. Normal operation, sleep, waiting 방식 등 파라미터로 다양한 튜닝이 가능.
  * <em>Lock 획득한 thread가 비정상 종료하면 DB를 down 시킴.</em>

* <strong>RW Lock(Read/Write Lock)</strong>
  1. Spinlock + RW 모드 정보를 추가한 lock 방식
  2. RW Lock의 Read 모드는 동시에 여러 thread가 잡을 수 있다.
  3. Critical Section에 수정이 드물고 Read 연산이 많은 경우 사용. 튜닝 불가
  * <em>Lock을 획득한 thread가 비정상 종료하면 DB를 down 시킴</em>

* <strong>WLock(Wait Lock)</strong>
  1. Logical Lock으로 다양한 mode가 존재(RS, RW, S, SRX, X)
  2. 어떤 Object를 보호하거나 어떤 작업 단위를 보호하기 위한 용도로 사용
  3. 사용자 로직에 따라 Deadlock 발생 가능
  * <em>Lock을 획득한 thread가 비정상 종료하면 다른 thread가 해당 lock을 원복 시켜 줌</em>

* <strong>CWS Lock(Cluster Wlock Service Lock)</strong>
  1. TAC에만 존재하는 Lock으로 WLock의 global lock.
  2. Wlock은 노드 내에서, CWS는 노드간 Lock이다.
  3. 노드간 lock정보를 저장하는 자료구조의 일부 튜닝이 가능.
  * <em>Lock을 획득한 thread가 비정상 종료하면 다른 thread가 해당 lock을 원복 시켜 줌</em>
3. DD/DDL Processing
<H2>DD(Data Dictionary) Overview</H2>
<em>DB를 운영하는데 필요한 meta data인 DD는 DDL을 수행하면서 여려 DD Table로 나뉘어 저장된다.</em>
* <strong>DD Tables</strong>
  1. _DD_OBJ
   - Object ID(Table ID)
   - Object Name(Table Name)
   - Object Type : Table
   - Schema ID :
   - 위와 같은 요소들을 컬럼으로 하여 테이블 생성.

  2. _DD_TBL
   - Object ID(Table ID)
   - Segment ID
   - Table Space ID
   - Number of columns : 

  3. _DD_COL
   - Object ID(Table ID)
   - Name of column :
   - Column Type :
   - Column number :
   - Schema ID :

* <strong>DD Tables in details</strong>
  1. _DD_OBJ
  <em>DB의 모든 Object(Table, Index..)에 대한 정보를 저장</em>
   - Object ID는 오브젝트 생성 시 발급되는 숫자로 유일한 값이다.
   - Schema ID는 스키마 생성 시 발급되는 유일한 숫자.
   - 새로운 오브젝트가 생성되면, _DD_OBJ 테이블에 해당 오브젝트 정보가 추가된다.

  2. _DD_TBL
  <em>DB의 모든 Table에 대한 정보를 저장</em>
   - Segment는 테이블의 오브젝트가 저장되는 공간을 나타내는 단위.
   - Table Space는 Segment들을 모아 놓은 컨테이너이다.
   - 새로운 테이블이 생성되면 _DD_OBJ 테이블과 더불어 _DD_TBL 테이블에 해당 테이블 정보가 추가된다.

  3. _DD_COL
  <em>DB의 모든 Table Column에 대한 정보를 저장</em>
   - Column Number는 Column의 순서 : create Table T (A number, B char); 에서 A = 0, B = 1.
   - 새로운 테이블이 생성되면, 테이블의 컬럼마다 해당 컬럼에 대한 정보를 _DD_COL 테이블에 저장.

* <strong>DD Cache</strong>
  <em>DD cache는 여러 DD Table을 join하여 쿼리 수행에 필요한 DD정보를 하나로 모아 메모리에 캐싱한다.</em>
  1. 일반적으로 Read-Only : DD정보가 변경되면 Cache를 직접 변경하지 않고 invalid표시만 하고 다음 접근 시 새로 load.
  2. DD cache를 직접 수정하는 예외 케이스로 sequence cache 옵션이 있다.
  3. Tibero Shared Memory의 Shared Pool 에 존재한다.
   - Shared Pool은 Libary Cache로 DD나 PP등을 위한 캐싱 목적으로 사용.
  4. DD Cache Search API(ddx_search)를 이용해서 DD_Cache 검색.
  5. Cache Miss가 발생할 경우에만 DD 테이블에 직접 접근한다.

<H2>DDL(Data Definition Language)</H2>
* <strong>DDL Overview</strong>
  1. DD(Data Dictionary)에 대한 수정
  2. DD cache, Physical Plan(PP) Cache invalidate.
  3. DDL Trigger(create, drop, alter.. table..) 수행.
* <strong>DDL Process</strong>
  1. Input : Create Table T (A number);
  2. Parse : Parse Tree and check syntax.
   - DDL 구문을 parsing할 때 Flex 및 Bison이라는 Tool을 사용
   - Flex : 구문을 토큰 단위로 분리.
   - Bison : Flex로부터 토큰을 받아서 문법 rule에 넣고 구문 트리 생성.
  3. Check : Check Semantic
   - DDL에 대한 수행 권한을 이 단계에서 검사.
   - Check 단계에서 새로운 트랜잭션 시작.
  4. Execute : DDL Execute.
   - 대부분 DD테이블에 대한 수정작업과 공간 관리 작업이 기본을 이룬다.
   - Create Table T (A number);
    + Table T에 대한 Object Id 발급
    + Table T에 대한 세그먼트 생성
    + DD정보 업데이트(_DD_OBJ, _DD_TBL, _DD_COL)
  5. Invalidate
   - 변경된 DD에 대한 DD Cache 및 PP Cache를 invalid.
   - DDL 수행은 DD에 대한 변경을 수반.
   - DD가 수정되면 PP(Physical Plan) 또한 수정.
  6. Commit
  7. After Commit
   - DDL 구문에 따라 TX(Transaction) commit이후 수행해야 하는 작업들을 수행
   - 예를 들어 Drop Table의 경우 실제 사용공간(Segment)반환은 DDL Commit 이후에 수행한다.
   - 이유는 공간 반환 작업은 Rollback이 안되기 때문이다. 만일 Commit 이전에 하면 DDL이 취소될 경우 반환된 공간을 다시 찾을 수 없다.

<H2>Lock Concept in DDL</H2>
* <strong>DD LocK</strong>
 <em>수행 중인 SQL이 참고하는 DD정보가 변하는 것을 보호하는 Lock</em>
  - DD Lock은 DB object단위로 관리된다.
  - DD Lock은 WLock이며 상황에 따라 wait, no-wait, timeout 모드를 사용.
  - DD Lock Level
   + RS(Row Share) : read lock(DD Search 수행 시 건다.)
   + SRX(Share Row Exclusive) : Read Lock과 호환되는 Write Lock(Read는 허용하여 Write는 no 허용)
   + X(Exclusive) : Write Lock(R/W 모두 허용하지 않는다)

* <strong>DML Lock</strong>
 <em>한 오브젝트에 대해 DML과 DDL의 동시 수행을 막기 위한 Lock</em>

* <strong>DDL DeadLock</strong>
 <em>DDL은 수행 구간마다 필요한 Lock Level이 다를 수 있기 때문에 Lock Level을 높이는 과정에서 deadlock이 발생(Up-Convert Deadlock).</em>
   - Up-Convert-Deadlock : Lock Level을 높이려는 행동이 두 세션에서 동시에 일어나면 발생.
   - RS->X로 Up-convert해주는 로직에 SRX lock을 no-wait으로 잡도록 하여 해결.(RS -> SRX(no-wait) -> X(wait)
