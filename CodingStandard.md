# C Coding Standard

0. 파일명
camel case를 쓴다. displayScreen.c

1. 변수명
* 전역변수는 접두어 g와 pascal case를 쓴다. ex) gVendingMachine
* 포인터 변수는 접두어 p를 붙인다. pMoney
* 구조체 타입명은 pascal case. Money
* 구조체 멤버변수는 camel case.
* no magic number.
```c
if ( input != 10 ) ...;
```

```c
struct Money{
  int coin500;
  int coin1000;
  int coin5000;
};
```
* 상수는 대문자. SEVENUP = 1000;
* enum 변수는 접두어 e를 붙이고, 내부변수는 대문자로 쓴다.
```c
enum drink {
SEVENUP,
COKE,
MILK,
...
};
drink eDrink;
```
2. 함수명
* camel case
* 결과를 저장하는 파리미터는 첫번째 인자로 쓴다. void add(int* result, int a, int b)

3. 들여쓰기, 공백
* 4칸, space
* 연산자 앞뒤 공백. result = a + b;

4. 괄호
* K&R or Allman.
ex) K&R
```c
if ( money == input ){
    ...;
}
```

5. 매크로
* 대문자
