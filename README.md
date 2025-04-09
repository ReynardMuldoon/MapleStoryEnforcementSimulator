# Equipment

장비를 나타낸 클래스: 

장비가 가지는 기본적인 것만 표현

후에 잠재 능력, 추가 옵션 등의 기능을 추가할 때의 확장성을 고려하여 각 기능에 관한 클래스를 생성하여 Composite으로 클래스 사이의 관계를 표현 

## 변수

- 장비 레벨 (int level)
- 스타포스 (StarForce starForce);

## 메서드

- Equipment(int _level, int _currentStarForce, long long _spareCost): 생성자
- Getter
    - StarForce& StarForce() { return starForce; }
        - StarForce 변수에 대한 참조자 반환
        - → Equipment 장비를 통해 StarForce 변수에 접근 가능
     


# StarForceSimulator
스타포스 강화 시뮬레이터 (= 스타포스 강화 관련 핸들러 클래스)

## 변수

- (std::vector<Equipment *>) equipments
    - 목표 스타포스 수치까지 강화 완료한 장비들을 보관
- (int) equipLevel: 장비 레벨
- (long long) spareCost: 스페어 장비 가격
- (int) startStarForce: 시작 스타포스 수치
- (int) goalStarForce: 목표 스타포스 수치
- (int) simulationCount: 시뮬레이션 횟수(= 목표 스타포스 수치까지 도달할 장비의 개수)

- (long long) totalCost: 총 누적 소모 비용
- (int) totalDestroy: 총 누적 파괴 횟수

## 메서드

- StarForceSimulator(int _equipLevel, long long _spareCost, int _startStarForce, int _goalStarForce, int simulationCount): 생성자
- ~StarForceSimulator(): 소멸자

- Getter:
    - long long TotalCost() const { return totalCost; }
    - int TotalDestroy() const { return totalDestroy; }
    - int SimulationCount() const { reutnr simulationCount; }

- void run(): 시뮬레이션 실행


# StarForce

## 변수

- (int) currentStarForce: 현재 스타포스 수치
- (int) maxStarForce: 최대 스타포스 수치
- (long long) spareCost: 스페어 장비의 가격
- (long long) totalCost: 누적 소모 비용
- (int) destroyCount: 누적 파괴 횟수

## 메서드

- Getter
    - CurrentStarForce
    - MaxStarForce
    - SpareCost
    - TotalCost
    - DestroyCount

- bool TryEnchant(int level): 강화 1회 시도

- void Succeeded(): 강화 성공 시 호출되는 함수
- void Failed(): 강화 실패 시 호출되는 함수
- void Destroyed(): 강화 실패로 인한 장비 파괴 시 호출되는 함수

- long long GetCost(int level) const: 현재 강화 1회 시도 시 필요한 비용 계산



# StarForce
스타포스 관련 정보 저장한 헤더 파일

## 1. 스타포스 성공 확률

## 2. 스타포스 파괴 확률

## 3. 스타포스 비용 요소

- 스타포스 비용 공식에 필요한 스타포스 수치에 따른 요소

## 4. 스타포스 최대 수치

- 장비 레벨에 따른 스타포스 최대 수치를 반환하는 함수
