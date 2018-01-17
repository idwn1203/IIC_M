# 연구실 관리 프로그램

## 전인준
### 전체설계
![Alt text](MainDisplay.PNG)
#### Leader
#### Member
- Todo list
- Time schedule
- Money

신상정보
이름
컴퓨터
	모니터
	RAM
CPU
HDD
SDD
발표일
학점평균
		상세보기
		학부
		석사
		박사
가능 언어
	C
C++
C#
Python
Java
	좌우명
	입사동기
	흥미분야



회식

놀이
모두의 마블
	인형뽑기

연구비 총액


### 연구실가계부


#### Display

1.가계부확인
2.가계부추가
<hr/>

(1)
번호/이름/입출금/내용분류/금액/날짜/시간/개인잔액/총잔액/비고

<hr/>

(2-0)
이름 :
1. 이원준
2. 임하슬린

<hr/>

금액 : UM원
<hr/>

입출금
1. 입금
2. 출금

<hr/>

사용방법
1.비품
2.회식
3.기타

<hr/>

비고 : x


****
#### Data
int AM  // 총 잔액
int 1M  // 이원준 잔액
int 2M  // 임하슬린 잔액
int UM // 사용금액
string x // 비고

#### Function
func0 : AM = M+-UM;
func1 : 1M = M+-UM;
func2 : 2M = M+-UM;

## 안해린
연구실 인원 관리부 요구사항
-이름
-학번
-등록일
-분류: 학/석/박사
-전체 인원

#Display
1. 명단
2. 신규
3. 삭제
0. 종료

명단
1. 전체
2. 수정
3. 삭제

수정 : 이름 검색해서

신규
1. 이름
2. 학번
3. 분류
4. 등록일

삭제

#Data
char name //학생이름
int number //학번
int date //등록일
char grade //분류
int num //총 학생 수

#Function
func1 : find students strcmp()
func2 : delete students , num--;
func3 : insert students , num++;

## 임하슬린
