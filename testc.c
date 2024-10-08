#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <string.h>



struct TPPS {
    int a;
    int b;
    int *c;
};
int arry[5]={0,1,2,3,4};
struct TPPS * func_with_struct_pointer_ret();
void init_arry(void){
	int arry[10]={0};
	
}
/// test_pointer_return_struct
int test_pointer_return_struct() {
    struct TPPS *a;
    a = func_with_struct_pointer_ret();
    if (a->c[3] == 3) {
        return 0;
    } else {
        return 1;
    }
}

int func_with_struct_pointer_para(struct TPPS *i);
int func_with_struct_pointer_para(struct TPPS *i)
{
    i->a=0;
	i->b=0;
	
	i->c=arry;
	return 0;
}


/// test_pointer_para_struct
int test_pointer_para_struct() {
    struct TPPS a;
    func_with_struct_pointer_para(&a);
    if (a.c[3] == 3) {
        return 0;
    } else {
        return 1;
    }
}


int func_with_pointer_para(int *i);

/// test_pointer_para
int test_pointer_para() {
    int i = 0;
    func_with_pointer_para(&i);
    if (i > 0) {
        return 1;
    } else {
        return 2;
    }
}

int test_read();

unsigned int Read_FlashFIFO[16];

void spi(unsigned int);

unsigned int test_search(unsigned long int Flash) {
    unsigned  int a, b, c, data;
    a = (Flash >> 8) & 0xFF00;
    b = (Flash) & 0xFF00;
    c = (Flash << 8) & 0xFF00;
    while (test_read() & 0x01);
    spi(a);
    spi(b);
    spi(c);
    for(int j=0; j < 16; j++) {
        Read_FlashFIFO[j] = 1;
    }
    data = Read_FlashFIFO[4];
    return data;
}

struct A33 {
    int a;
};

struct A22 {
    int a;
    struct A33 a33;
};

struct A11 {
    int a;
    int b;
    struct A22 a22;
    struct A33 a33;
    struct B11 *b11;
    struct {
        int c;
        int d;
    };
    union {
        int a;
        int b;
    } m;
};

struct B11
{
    struct A11 a11;
};

struct {
    int a;
    int b;
} g_anonymous;

///test_complex_struct_nested_1
void test_complex_struct_nested_1(struct A11 a11, struct B11 *b11, struct A22 *a22)
{
    if(g_anonymous.a > 0) {
        g_anonymous.a = 1;
    }

    if(a11.a > 0) {
        a11.a = 1;
    }
}

/// test_complex_struct_nested
void test_complex_struct_nested(struct A11 a11, /*struct B11 b11,*/ struct A22 a22) {
    if (g_anonymous.a > 0) {
        g_anonymous.a = 1;
    }
    if (a11.a > 0) {
        a11.a = 1;
    }
}

struct AAA {
    int a;
};

struct BBB {
    int a;
    struct AAA aa;
};



int test_sta(int a)
{
	
	static int c=0;
	static int n=0;
	int x=0;
	if((c<10)&&(c>5))
	{
		if(a==10)
		{
			n=1;
			
		}
		
		
	}
	else if(c<20)
	{
		
		if((n==1)&&(a==5))
		{
			x=1;
		}
	}
	else
	{
		
	}
		c++;
		return x;
}

int test_mcdc(int a,int d)
{
	
	static int c=0;
	static int n=0;
	int x=0;
	if((c<10)&&(c>5)&&(d > 0))
	{
		if(a==11)
		{
			n=1;
			
		}
		
		
	}
	else if(c<20)
	{
		
		if((n==1)&&(a==5))
		{
			x=1;
		}
	}
	else
	{
		
	}
		c++;
		return x;
}

/// test_nest_structAA
void test_nest_structAA(struct BBB *bb) {
    int a;
    if (bb[0].aa.a == 1) {
        a = 1;
    }
}

extern int test_e;

/// test_extern_variable
int test_extern_variable() {
    if (test_e > 0) {
        return 0;
    } else {
        return 1;
    }
}

/// test_static_local
int test_static_local() {
    static int a = 0;
    if (a > 0) {
        return 1;
    } else {
		a++;
        return 2;
    }
}

/// test_memset
void test_memset(char *a, int size) {
    memset(a, 0, size);
}

/// test_strcpy
void test_strcpy() {
    char a[3];
    a[0] = 'a';
    a[1] = 'a';
    a[2] = 0;
    char b[3];
    b[0] = 'a';
    b[1] = 'a';
    b[2] = 0;
    strcpy(a, b);
}

/// test_abs
int test_abs(float a) {
    if (fabs(a) == a) {
        return 0;
    } else {
        return 1;
    }
}

struct ATest{
    char a;
    char b;
    int c;
};

int ab[20];

//#pragma pack(4)
typedef struct {
    //struct A a[2];
    //int b;
    char age ;
    char  age1 ;

    short a[10];

    char ac ;
} Age;
//#pragma pack()

/// test_multi_paras
void test_multi_paras(Age b, struct ATest a)
{

    if(a.a == 1) {

    }

    if(a.b == 5) {

    }

    if(a.c == 10) {

    }

}
#define RAM_ADDR     (*(volatile unsigned long  *)0x0000555F)
/// test_absolute_address_read
int test_absolute_address_read  () {
    int j = *((int *) (2));
    int k = *((int *) (2));
	int tmp = RAM_ADDR;
    RAM_ADDR = 0x55;
    *((int *) (4)) = 3;
    if (j == k) {
        
    } else {
        
    }
	if(tmp==0x11)
	{
		
	}
}

/// test_absolute_address_write
int test_absolute_address_write() {
    *((int *) (2)) = 3;
    *((int *) (2)) = 4;
	int tmp = RAM_ADDR;
    RAM_ADDR = 0x55;
    return 1;
}


/// test_printf
void test_printf() {
    printf("abc");
}

/// test_dynamic_parameter
int testdp(int a, ...) {
    va_list ap;
    va_start(ap, a);
    int b = va_arg(ap, int);
    va_end(ap);
    if (b > 0) {
        return 1;
    } else {
        return 2;
    }

}

/// test_dynamic_parameter
int test_dynamic_parameter(int i) {
    return testdp(1, i);
}

/// test_sqrt
int test1(double a) {
    double b = sqrt(a);
    if (b == 3) {
        return 1;
    } else {
        return 0;
    }
}

struct TestP1 {
    int a;
    int b;
};

struct TestP2 {
    struct TestP1 *a;
    int b;
    int c;
};

int test_struct_first_field_pointer(struct TestP2 *t) {
    t->b = 1;
    if (t->a->a > 0) {
        return 1;
    } else {
        return 2;
    }
}

struct {
    int a;
    int b;
} A, *B;

/// test_anonymous_struct
int test_anonymous_struct() {
    if (A.a > 0) {
        return 1;
    } else {
        return 2;
    }
}

/// test_anonymous_struct_pointer
int test_anonymous_struct_pointer() {
    if (B->a > 0) {
        return 1;
    } else {
        return 2;
    }
}

union U {
    int *a;
    long b;
};
union U e[2];

union U e1;

/// test_union_global_1
int test_union_global_1(long a) {

    if (e[0].a[0] == 5) {
        return 3;
    }

    if (e[1].b == 5) {
        return 4;
    }

    return 2;
}

/// test_union_global_2
int test_union_global_2(union U test) {
    if (e1.a[0] == 5) {
        return 3;
    }

    if (test.a[0] == 5) {
        return 4;
    }

    return 2;
}


///test_void_pointer
int test_void_pointer(void *test) {
    int *a = (int *)test;
    if (a[3] > 1) {
        return 1;
    } else {
        return 2;
    }
}

typedef char (*funp)(int a);

/// test_function_pointer
int test_function_pointer(funp fun) {
    char a = fun(2);
    if (a > 0) {
        return 0;
    } else {
        return 1;
    }
}


int g1[10];
int *g2;

/// test_global_assignment
int test_global_assignment() {
    g2 = g1;
    if (g2[2] > 0) {
        return 1;
    } else {
        return 0;
    }
}

///test_rem
int test_rem(int a, int b) {
    a = a % b;
    if (a > 0) {
        return 1;
    } else {
        return 2;
    }
}

int test3() {
    return 1;
}

/// test_precision
int test_precision() {
    int a = test3();
    if (a > 0) {
        return 1;
    } else {
        return 2;
    }
}


extern int test2();

/// test_symbolize_global
int test_symbolize_global() {
    int a = test2();
    if (a > 0) {
        int b = test2();
        if (b > 3)
            return 0;
        else
            return 4;
    } else {
        return 1;
    }
}

struct AG2 {
    int a;
};

struct AG1 {
    int a;
    struct AG2 *b;
};

struct AG {
    int a;
    int *b;
    int c;
    int d;
    int f;
    int e;
    int g;
};

struct ABCD {
    void *a;
    int b;
};

int test_ABCD(struct ABCD *a) {
    if (a->b > 0) {
        return 0;
    } else {
        return 1;
    }
}

/// test_dynamic_type_1
void test_dynamic_type_1(void *a)
{
    int b;
    struct ABCD * a1 = (struct ABCD *)a;
    int * a2 = (int *)a1->a;

    if(a1->b == 1) {
        b = 1;
    }
    if(a2[0] == 3) {
        b = 2;
    }

}

/// test_dynamic_type
int test_dynamic_type(struct AG1 *t) {
    struct AG *a = (struct AG *) t->b;
    if (a->b[3] > 0) {
        return 1;
    } else {
        return 0;
    }
}

struct AG global_struct;
struct AG *global_struct_pointer;
struct AG global_struct_array[10];

/// test_global
int test_global(int a) {
    if (a > global_struct.a) {
        return 0;
    } else {
        if (global_struct.b[4] > 5) {
            return 1;
        } else {
            return 2;
        }
    }
}

/// test_global_pointer
int test_global_pointer(int a) {
    if (a > global_struct_pointer->a) {
        return 0;
    } else {
        if (global_struct_pointer->b[4] > 5) {
            return 1;
        } else {
            return 2;
        }
    }
}

/// test_global_array
int test_global_array(int a) {
    if (a > global_struct_array[4].a) {
        return 0;
    } else {
        if (global_struct_array[4].b[4] > 5) {
            return 1;
        } else {
            return 2;
        }
    }
}

//
// Created by Zhenbang Chen on 1/26/17.
//

int test(int i) {
    return i + 1;
}

#ifdef __cplusplus
extern "C" {
#endif

void secore_symbolize(void *address, unsigned int size);

#ifdef __cplusplus
}
#endif

/// test_malloc
int test_malloc() {
    int *p = malloc(sizeof(int) * 4);
    secore_symbolize(p, sizeof(int) *4);
    if (p[2] > 0) {
        return 1;
    } else {
        free(p);
        return 2;
    }
}

struct A {
    int a;
    int b;
};


struct B {
    double a;
    int *b;
    int *d;
    struct A *c;
};

struct C {
    float *a;
};


struct D {
    double a;
    int *b;
    int *d;
    struct C *c;
};

struct E {
    int *a;
    struct D *b;
};

typedef struct {
    int a;
    struct E b;
} F;

typedef struct {
    struct A a;
    int b;
} G;


typedef struct {
    float *a;
} AA;

typedef struct {
    AA a;
} BB;

typedef struct {
    BB a;
} CC;

typedef struct {
    CC a;
} DD;

struct Z {
    int a[5];
};


union UU {
    int a;
    int b;
    double c;
};

enum AE {
    a1 = 5,
    a2
};

union UU1 {
    int *a;
    double c;
};


struct ABit {
    char a:1;
    char b:7;
    int *c;
};

#pragma  pack(2)

struct ABit1 {
    int a:1;
    int b:2;
    int c:1;
	int d:8;
	int short1:16;
	int integer:32;
};

#pragma  unpack

typedef union {
    char a;
    int b;
    float c;
    double *d;
} unionA;

typedef struct {
    unionA a;
    unionA *b;
    unionA c[5];
} structA;

///test_union_pointer_array
int test_union_pointer_array(unionA test) {
    if (test.d[4] > 5.0) {
        return 0;
    } else {
        return 1;
    }
}

/// test_union_complex
int test_union_complex(structA test) {
    if (test.b->d[2] > 5.0) {
        return 0;
    } else {
        return 1;
    }
}

/// test_struct_bit
int test_struct_bit(struct ABit1 *a) {
    if (a->a == 1) {
        return 1;
    } else {
        return 2;
    }
}

/// test_union_pointer
int test_union_pointer(union UU1 *a) {
    if (a->a[2] == 2) {
        return 1;
    } else {
        return 2;
    }
}

/// test_enum
int test_enum(enum AE t) {
    if (t == a1) {
        return 1;
    } else {
        return 2;
    }
}

/// test_union
int test_union(union UU *a) {
    if ((a->a + a->b) == 2) {
        return 1;
    } else {
        return 2;
    }
}


/// test_switch
int test_switch(int i) {
    switch (i) {
        case 1:
        case 10:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        default:
            return 4;
    }
}

/// test_struct_array_element
int test_struct_array_element(struct Z a) {
    if (a.a[3] == 5) {
        return 1;
    } else {
        return 2;
    }
}

/// test_struct_array
int test_struct_array(struct B test[]) {
    if (test[1].b[3] > 0) {
        return 0;
    } else {
        return 1;
    }
}

/// test_nested_typedef
int test_nested_typedef(DD *t) {
    if (t->a.a.a.a[5] > 11.1) {
        return 0;
    } else {
        return 1;
    }
}

/// wxb_test_simple_struct
int wxb_test_simple_struct(G test) {
    if (test.b > 11) {
        if (test.a.a + test.a.b < 11) {
            return 2;
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

/// wxb_test_struct_field_complex
int wxb_test_struct_field_complex(F *struct_f, struct B struct_b) {
    if (struct_f->a > 2) {
        return 1;
    } else {
        if (struct_f->b.a[3] == 5) {
            return 2;
        } else {
            if (struct_f->b.b->a == 11.1) {
                return 3;
            } else {
                if (struct_b.a == 11.1) {
                    return 4;
                } else {
                    if (struct_b.c->a > 8) {
                        return 5;
                    } else {
                        return 6;
                    }
                }
            }
        }
    }
}


/// test_typedef
int test_typedef(F *test) {
    if (test->b.a[3] == 5) {
        return 1;
    } else {
        return 0;
    }
}


/// test_watchdog
int test_watchdog(int i) {
    while (i < 0) {
        i--;
    }
    return i;
}

/// test_double_pointer_integer
int test_double_pointer_integer(double *a, int i) {
    if (a[i] > 100) {
        return 0;
    } else {
        return 1;
    }
}


/// test_double_pointer
int test_double_pointer(double *a) {
    if (a[1] == 10.0) {
        return 1;
    } else {
        return 2;
    }
}

/// test_char_a
int test_char_a(char *a, char *b) {
    int index = 24 / 6;
    if (a[0] == b[0]) {
        return 1;
    } else if (a[index] == b[index]) {
        return 2;
    } else {
        return 0;
    }
}

/// test_struct_field
int test_struct_field(struct B *test) {
    if (test->c->a == 11) {
        if (test->b[10] == 3) {
            return 1;
        } else if (test->d[3] == 4) {
            return 2;
        }
        return 0;
    } else {
        return 3;
    }
}

/// wxb_test_struct_field
int wxb_test_struct_field(struct E *test) {
    if (test->b->c->a[5] == 11) {
        if (test->b->b[10] == 3) {
            return 1;
        } else if (test->b->d[3] == 4) {
            return 2;
        }
        return 0;
    } else {
        return 3;
    }
}


/// test_while
int test_while(unsigned int a) {
    while (a > 0 && a < 5) {
        a--;
    }
    return 1;
}

/// test_divbyzero
double test_divbyzero(double a, int b , float s, long m) {
	int i;
	float k;
	i = a / b;
	k = s / a;
	k = m / s;
	k = b / a;
    if (a == 5) {
        return a / b;
    } else {
        return i;
    }
}

/// test_int_pointer
int test_int_pointer(int *a, int i) {
    if (i >= 0 && a[i] > 0) {
        if (a[i + 1] < 0) {
            return 1;
        } else {
            return 2;
        }
    }
    return 3;
}

/// test_char
int test_char(char a, char b, char c) {
    char t = 0x12;
    if (a == 'c') {
        if (b == 'a' && c == 'b') {
            return 1;
        } else {
            return 2;
        }
    }
    return 0;
}

/// test_float_1
int test_float_1(float a) {
    if ( a == 15) {
        return 1;
    } else {
        return 0;
    }
}

/// test_float
int test_float(float a) {
    if (a * a * a == 8) {
        return 0;
    } else {
        return 1;
    }
}

/// test_overflow
int test_overflow(int a, int b) {
    if (a > 0 && b > 0) {
        if ((a + b) < 0) {
            return 1;
        } else {
            return 2;
        }
    }
    return 0;
}

/// test_bfs
int test_bfs(int a, int b) {
    if (a == 0) {
        if (b == 0) {
            return 1;
        } else {
            return 2;
        }
    } else {
        if (b == 3) {
            return 3;
        } else {
            return 4;
        }
    }
}


/// test_UC_multiple_arguments_pointer_pointer_integer_integer
int test_UC_multiple_arguments_pointer_pointer_integer_integer(int *a, int *b, int i, int j) {
    if (a[i] > 10) {
        if (b[j] > 100) {
            return 1;
        } else {
            return 2;
        }
    } else {
        return 3;
    }
}

/// test_UC_multiple_arguments_pointer_integer
int test_UC_multiple_arguments_pointer_integer(int *a, int i) {
    if (a[i] > 0) {
        return 1;
    } else {
        return 0;
    }
}

/// test_UC_multiple_arguments
int test_UC_multiple_arguments(int a, int b) {
    if (a > 90) {
        if (b > 20) {
            return 1;
        } else {
            return 2;
        }
    } else {
        return 3;
    }
}

/// test_UC_se_symbolic_pointer_write_complex
int test_UC_se_symbolic_pointer_write_complex(int *a) {
    a[0] = 1;
    int *b = a;
    b++;
    if (b[1] > 1) {
        int *c = a;
        if (c[1] > 1)
            return 1;
        else
            return 2;
    } else {
        return 0;
    }
}

/// test_UC_se_symbolic_pointer_write
int test_UC_se_symbolic_pointer_write(int *a) {
    a[5] = 1;
    if (a[5] > 1) {
        return 1;
    } else {
        return 0;
    }
}

/// test_UC_se_symbolic_pointer
int test_UC_se_symbolic_pointer(int *a) {
    if (a[1] > 0) {
        return 1;
    } else {
        return 0;
    }
}

/// test_UC_se_symbolic_int
int test_UC_se_symbolic_int(int a) {
    if (a > 0) {
        return 1;
    } else {
        return 0;
    }
}

/// test_assign
int test_assign(int *a) {
    a[2] = 1;
    return a[2];
}

enum State {
    SET,
    UNSET
};

enum State getState();

void test_return_enum() {
    int b = 0;
    enum State a = getState();
    if(a == SET) {
        b = 1;
    } else {
        b = 2;
    }
}

typedef struct DataTime
{
	unsigned int a ;
	int b;
	int data[6];
	structA sa;
};
typedef struct strUpDataTime_1
{   
    
	unsigned char type;
	unsigned int time;
	unsigned int **poin;
	struct DataTime DATA[6];
}UP_DATA_TIME_1;
UP_DATA_TIME_1 g_strUpDataTime_1[6][5];

/*
unsigned int fModifyTime_1(unsigned int addr,unsigned char num,unsigned char step)
{
	//二维结构体
    unsigned int n_uiTime;
    //n_uiTime = fReadInt(addr);
	if(g_strUpDataTime_1[num].DATA[step].data[10]==10)
	{
		return g_strUpDataTime_1[num].DATA[step].a;
		
	}
    if(g_strUpDataTime_1[step].type == 0xaa)/*替换新的时间*//*
    {
        return g_strUpDataTime_1[step].time;
    }
    else
    {
        return n_uiTime;
    }
}
*/
char *str=NULL;
void GetMemory(char**p,int num)
{
	*p=(char*)malloc(num);
}

void Test(void)
{
	
	GetMemory(&str,100);
	if(str==NULL)
	{
		return ;
	}
	strcpy(str,"hello");
	printf(str);
	free(str);
	str=NULL;
	
}
void pointer(int** p)
{
	
	if( p[1][2]==3)
	{
		
		int a=0;
		
	}	
}


int func_t(UP_DATA_TIME_1 **ai)
{
	int i = 0;
	*ai = *g_strUpDataTime_1;
	ai[0][0].time = 0;
	for(; i<ai[0][0].type; i++)
	{
		ai[i][i].time = i;
	}
	
	if(ai[i][i].time > 10)
	{
		return 0;
	}
		return 1;
}




unsigned short g_usBrcstTimeBuf[4];
unsigned short g_usBrocTime[3];
unsigned int g_uiSysTime[3];
unsigned int g_uiSatChkTimerFlag;
#define Ace_Mem_Base 0
#define aceRegWrite(aceReg,data) ((*(unsigned int*)(aceReg))=(unsigned int*)(data))
#define	aceMemRead(aceMem)       ((unsigned short) ((*(unsigned int *)((aceMem)*4+(Ace_Mem_Base)))))
#define Time_Tag_REG 66
#define IMMEVENT_NUM 5 
#define IMMEVENT_PER_LEN 6
#define WORK_TABLE_NUM 33
void fDealBrocTimeInfo(unsigned short msp)
{
	//绝对地址
    unsigned short dp,i;
    unsigned int n_uiEomTime,n_uiRandomDelay;
    unsigned short n_usChkTimeType;
    unsigned char n_ucRec,n_ucCur;
    unsigned char n_ucTempBrocTime[6];
    dp = aceMemRead(msp + 2);
    n_uiEomTime = aceMemRead(msp + 1);/*读取消息时间标签*/
     
    for(i = 0; i < 4; i = i + 1)
    {
        g_usBrcstTimeBuf[i] = aceMemRead(dp+i);
       // logMsg("BrocTimeNo.%04x = %04x\n",i,g_usBrcstTimeBuf[i],0,0,0,0);   
         
    }
    n_usChkTimeType = g_usBrcstTimeBuf[0];
    g_usBrocTime[0] = g_usBrcstTimeBuf[1];
    g_usBrocTime[1] = g_usBrcstTimeBuf[2];
    g_usBrocTime[2] = g_usBrcstTimeBuf[3];
     
    n_ucRec = (unsigned char)(g_usBrocTime[0]>>8);
    n_ucCur = (unsigned char)(g_uiSysTime[0]>>24);
    if(n_ucRec>=n_ucCur)
    {
        g_uiSysTime[0] = ((unsigned int)g_usBrcstTimeBuf[1]<<16)|(unsigned int)g_usBrcstTimeBuf[2];
        g_uiSysTime[1] = g_usBrcstTimeBuf[3];
        n_uiRandomDelay = aceMemRead(Time_Tag_REG);
        aceRegWrite(Time_Tag_REG,0);/*clear ace time tag register,and clear time rest*/
        g_uiSysTime[2] = 0;
        /*补偿1553B传输时间和语句处理时间*/
        if(n_uiRandomDelay >= n_uiEomTime)
        {
            n_uiRandomDelay = n_uiRandomDelay - n_uiEomTime;
        }
        else
        {
            n_uiRandomDelay = 0x10000-n_uiEomTime + n_uiRandomDelay;
        }
        n_uiRandomDelay = (n_uiRandomDelay << 6) +80;/*传输1Mbps，传输8字节大概需要的时间，单位us*/
        if((n_uiRandomDelay % 100)>=50)/*四舍五入*/
        {
            n_uiRandomDelay = n_uiRandomDelay/100;/*100us的计数*/
            n_uiRandomDelay = n_uiRandomDelay + 1;  
        }
        else
        {
            n_uiRandomDelay = n_uiRandomDelay/100;
        }
        g_uiSysTime[1] = g_uiSysTime[1] + n_uiRandomDelay;
        g_uiSysTime[0] = g_uiSysTime[0] + (g_uiSysTime[1]>>16);
        g_uiSysTime[1] = g_uiSysTime[1] & 0xFFFF;
             
        g_uiSatChkTimerFlag = 0x5A5A5A5A;
    }
     
}



unsigned short g_usInjectMultCnt;
unsigned char g_ucNewCodeFlag;
unsigned char g_ucInjectErrType;
unsigned char g_ucImmEventCnt;
unsigned int g_uiNewCodeLeng;
unsigned char g_ucInjectErrCnt;
unsigned char g_ucInjectFrameNum;
unsigned char g_ucUploadFlag;
unsigned char g_ucInjectExeCnt;

unsigned short g_usUpPromPakFlag;
unsigned short g_usInjectDataBuf[150];
unsigned int g_uiUploadLen;
unsigned int g_uiNewCodeBuf[30];
unsigned short g_usImmEventTable[10][5];/* 立即指令表 */
void fDataInjectMove(UP_DATA_TIME_1 **n_uiEomTime, int ks)
{
	//不明原因
    unsigned short n_usPakCnt, n_usPakFlag;
    unsigned short n_usIdx,n_usIdy;
    unsigned int n_uiKdx;
    unsigned int n_uiWrAddr;
    unsigned short n_usLength,n_usDataType;
    unsigned int n_uiDataTmp;
    unsigned char n_ucPayLoadNum,n_ucSatelliteNum,n_ucRsIndexNum;
    unsigned char n_ucWorkTableNum,n_ucWorkStepNum;
     
    unsigned short* pBuf;
    unsigned short n_usPakLen,n_usLenTmp1,n_usLenTmp2;
	*n_uiEomTime = *g_strUpDataTime_1;

     
/*  unsigned int n_uiSrcAddr;*/
     
    n_usPakFlag = g_usInjectDataBuf[1] & 0xC000;  /* 分组标识 */
    n_usPakCnt  = g_usInjectDataBuf[1] & 0x3FFF;    /* 包序号 */
    if(0xC000 == n_usPakFlag)/* 独立包 */
    {
        g_ucInjectFrameNum = g_ucInjectFrameNum + 1;/* 数据注入帧计数加1 */
        if(g_usInjectDataBuf[3] == 0x000A)/*功能注数-立即执行数据注入*/
        {
            if(g_usInjectDataBuf[2] == 0x000D)/*常用数据注入指令包长度固定为0x0d*/
            {
                    if(g_ucImmEventCnt < IMMEVENT_NUM )
                    {
                        for(n_usIdx = 0; n_usIdx < IMMEVENT_NUM; n_usIdx = n_usIdx + 1)
                        {
                            if(g_usImmEventTable[n_usIdx][0] == 0)
                            {
                                g_usImmEventTable[n_usIdx][1] = g_usInjectDataBuf[4];/* 立即指令内容--码字 */
                                g_usImmEventTable[n_usIdx][2] = g_usInjectDataBuf[5];/* 立即指令内容--指令内容 */
                                g_usImmEventTable[n_usIdx][3] = g_usInjectDataBuf[6];/* 立即指令内容--指令内容 */
                                g_usImmEventTable[n_usIdx][4] = g_usInjectDataBuf[7];/* 立即指令内容--指令内容 */
                                g_usImmEventTable[n_usIdx][5] = g_usInjectDataBuf[8];/* 立即指令内容--EEPROM指令编号 */
                                g_usImmEventTable[n_usIdx][0] = 0x5A;/* 置上更新标识 */
                                g_ucImmEventCnt = g_ucImmEventCnt + 1;
                                break;
                            }
                        }
                    }
                    else
                    {
                        g_ucInjectErrCnt = g_ucInjectErrCnt + 1;
                        g_ucInjectErrType = 0x77;/* 事件表满 */
                    }
            }
            else
            {
                g_ucInjectErrCnt = g_ucInjectErrCnt + 1;
                g_ucInjectErrType = 0x22;/* 数据注入指令长度错误 */
            }
        }
        else if(n_uiEomTime[0][1].DATA->data[4]== 0x000B)/*功能注数-大型数据块数据注入*/
        {
            n_usPakLen = g_usInjectDataBuf[2] + 1;/* 字节长度 =  功能识别2字节+数据内容N字节+4字节数据内容校验和+2字节数据包校验和 */
            n_usLenTmp1 = (n_usPakLen-8)%4;
            n_usLenTmp2 = (n_usPakLen-4)/2;/*数据内容+数据内容校验和的2字长度*/
            g_uiUploadLen = (n_usPakLen-8)/4;/*数据内容的4字节长度*/
            if((n_usPakLen>=12)&&(n_usPakLen<=248)&&(n_usLenTmp1 == 0))
            {
                pBuf = (unsigned short*)&g_uiNewCodeBuf[0];
                for(n_usIdy = 0; n_usIdy < n_usLenTmp2; n_usIdy = n_usIdy + 1)
                {
                    pBuf[n_usIdy] =  g_usInjectDataBuf[n_usIdy+4];
                }
                g_ucInjectExeCnt = g_ucInjectExeCnt + 1;
/*              g_ucInjectFrameNum = g_ucInjectFrameNum + 1;*//* 数据注入帧计数加1 */
/*              g_uiNewCodeSum = 0;*/
                g_ucNewCodeFlag = 0x3c;/*开始对数据内容缓冲区进行校验*/
/*              logMsg("g_ucNewCodeFlag = 0x3c !!!!\n",0,0,0,0,0,0);*/
            }
            else
            {
                g_ucInjectErrCnt = g_ucInjectErrCnt + 1;
                g_ucInjectErrType = 0xDD;/* 数据注入内容错误-修改长度错误 */
            }
        }
        else
        {
            g_ucInjectErrCnt = g_ucInjectErrCnt + 1;
            g_ucInjectErrType = 0x44;/* 数据注入功能识别错误 */
        }
    }
    else if(0x4000==n_uiEomTime[0][1].DATA->a && 0x4000==n_uiEomTime[0][1].DATA->b)/*首包*/
    {
        g_usInjectMultCnt = 0;
        if(g_usInjectDataBuf[2] == 0x00F9)/*程序上载包长度固定为0xF9*/
        {
            if(n_usPakCnt == 0)
            {
                if(g_usInjectDataBuf[3] == 0x000B)
                {
                    pBuf = (unsigned short*)&g_uiNewCodeBuf[0];
                    for(n_usIdy = 0; n_usIdy < 20; n_usIdy = n_usIdy + 1)
                    {
                        pBuf[n_usIdy] = g_usInjectDataBuf[4+n_usIdy];
                    }
                    g_uiNewCodeLeng = 123;  /* 已注入程序代码的2字长度 */
                    g_usInjectMultCnt = g_usInjectMultCnt+1;    /* 首包-数据注入多包计数置1 */
                    g_usUpPromPakFlag = 0x5555; /*包控制序置为首包*/
                    g_ucInjectExeCnt = g_ucInjectExeCnt + 1;
                }
                else
                {
                    g_ucInjectErrCnt = g_ucInjectErrCnt + 1;
                    g_ucInjectErrType = 0x44;/* 数据注入功能识别错误 */
                }
            }
            else
            {
                g_ucInjectErrCnt = g_ucInjectErrCnt + 1;
                g_ucInjectErrType = 0x99;/*首包包序号不为0*/
            }
        }
        else
        {
            g_ucInjectErrCnt = g_ucInjectErrCnt + 1;
            g_ucInjectErrType = 0x22;/* 数据注入指令长度错误 */
        }
    }
    else/*中间包*/
    {
        if(g_usInjectDataBuf[2] == 0x00F9)/*程序上载包长度固定为0xF9*/
        {

			g_ucInjectErrCnt = g_ucInjectErrCnt + 1;
			g_ucInjectErrType = 0xAA;/*中间包序错误*/
        }
        else
        {
            g_ucInjectErrCnt = g_ucInjectErrCnt + 1;
            g_ucInjectErrType = 0x22;/* 数据注入指令长度错误 */
        }
    }
    return;
}


int test_func3(int aaa)
{
	if(aaa == 1)
		return 1;
	else if(aaa == 2)
		return 2;
	return 3;
}


typedef struct strUpDataTime
{
	unsigned char type;
	unsigned int time;
}UP_DATA_TIME;
UP_DATA_TIME g_strUpDataTime[WORK_TABLE_NUM][64];


unsigned int fModifyTime(unsigned int addr,unsigned char num,unsigned char step)
{
	//二维结构体
    unsigned int n_uiTime;
    n_uiTime = 1;
    if(g_strUpDataTime[num][step].type == 0xaa)/*替换新的时间*/
    {
        return g_strUpDataTime[num][step].time;
    }
    else
    {
        return n_uiTime;
    }
}


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <string.h>


#define MAX_GRAY_LEVEL 128
#define IMG_HEIGHT 128
#define IMG_WIDTH 128

typedef unsigned short UINT16;
typedef UINT16 PIXELTYPE;
typedef signed int SINT32;

typedef struct tagSEGMENT_LINE
{
	SINT32 start;
	SINT32 finish;
}SEGMENT_LINE;


SINT32 GetBkginfo(PIXELTYPE* pImg,SEGMENT_LINE* pRgn){
	SINT32 i,j;
	SINT32 GreyNum[MAX_GRAY_LEVEL + 1];
	
	memset(GreyNum,0,sizeof(SINT32) * (MAX_GRAY_LEVEL + 1));
	for(i = 0;i < IMG_HEIGHT; i++){
		for(j = 0;j <= 128;j++){
			GreyNum[pImg[i * IMG_WIDTH + j]]++;
			
		}
	}
	for(i = 0;i < MAX_GRAY_LEVEL; i++){
		GreyNum[i + 1] = GreyNum[i + 1] + GreyNum[i];
	}
	i = 1;
	while(GreyNum[i] < (GreyNum[MAX_GRAY_LEVEL] >> 4)){
		i++;
	}
	return i - 1;
}

//typedef unsigned short UINT16;
typedef struct{
	UINT16 wparaindex;
	UINT16 wparatype;
	UINT16 wCRC;
	UINT16 wParaL;
	UINT16 wParaH;
	
}PARA_PACKAGE_DATA;


typedef union{
	PARA_PACKAGE_DATA word;
	UINT16 all[5];
}PARA_PKG_DATA;

enum _ParaIndex{
	Para_Sys_Serial_Ctrl = 100,
	Para_Sys_Ver_soft = 101,
	Para_Sys_Serial_Reg = 102,
	Para_Sys_Max = 103,
	Para_CRC = 104
};

void paraUpdate(UINT16 wData[]){
	PARA_PKG_DATA pkg;
	char bDat[4];
	UINT16 wCRC = 0;
	memcpy(pkg.all,wData,sizeof(pkg.all));
	
	if(pkg.all == NULL){
		int i = 0;
	}
	
	if(wData == NULL){
		int i = 1;
	}
	
	if(pkg.all[2] == 0){
		int i = 2;
	}
	
	if(pkg.word.wparaindex == Para_CRC){
		int i = 3;		
	}
}

struct app{
    int a;
    int b;
    int c;
	int *e;
};

void func_struct_para(struct app *i)
{
	if(i->a > 10){
		i->a = 100;
		i->b = 101;
		i->c = 102;
		i->e = NULL;
	}
	else{
		i->a = 108;
		i->b = 109;
		i->c = 110;
		i->e = NULL;
	}   
}

int test_pointer_parament(){
    struct app a;
    func_struct_para(&a);
	
	if(a.e[2] > 10){
		return 1;
	}
	else{
		return 1;
	} 
}
 

int test_pointer_para1(){
    struct app *a;
	struct app temp;
	a = &temp;
    func_struct_para(a);
	if(a->c == 102){
		a->b+=1;
		return a->b;
	}
	else{
		a->b+=2;
		return a->b;
	}
	if(a->e[2] > 10){
		a->b+=3;
		return a->b;
	}
	else{
		a->b+=4;
		return a->b;
	} 
}

int test_max_while(unsigned int i)
{ 
	i = 0;
    while (1){
        i++;
		if(i >= 6)
		{
			return i;
		}
    }
    return 0;	
}

int product(int a)
{
  
  if(a<0)
  {
    printf("error\n");
	return 5;
  }else if(a==0||a==1)
  {
    return 1;
  }else{
    return a*product(a-1);
  }         
}

#define WIDTHBYTES(bits) (((bits)+31) / 32 * 4)





typedef unsigned short UINT16;
typedef signed short SINT16;
typedef unsigned int UINT32;
typedef signed int SINT32;
typedef unsigned char UINT8;
typedef signed char SINT8;
typedef float REAL32;
typedef double REAL64;
typedef UINT16 PIXELTYPE;
typedef SINT16 SPIXELTYPE;
typedef PIXELTYPE TPLATEIMGTYPE;
typedef UINT8 EDGEIMGYTYPE;

typedef struct tagCIRCLE_CHAR
{
	SINT16 CenRow;
	SINT16 CenCol;
	SINT16 Radius;
	SINT16 RegionID;
}CIRCLE_CHAR;



void HoughtTransFixRadius(UINT8* lpDIBBits,SINT32 lWidth,SINT32 lHeight,SINT32 radius,SINT32* TransResult,SINT32 edgevalue,REAL32 th0);
SINT32 EdgeCirqueCorrMatchForPoint(UINT8* lpDIBBits,SINT32 lWidth,SINT32 lHeight,REAL32 radius,SINT32 x0,SINT32 y0,SINT32 edgevalue,SINT32* pNumOfTemplate);

void HoughTransFindCirque(UINT8* lpDIBBits, SINT32 lWidth, SINT32 lHeight, SINT32 edgevalue, CIRCLE_CHAR *cir)
{
	SINT32 i;
	SINT32 j;
	SINT32 num;
	SINT32 lLineBytes;
	REAL32 ratio;
	UINT8 lpNewDIBBits[IMG_HEIGHT*IMG_WIDTH];
	SINT32 cirInRad = 3;
	SINT32 cirOutRad = 50;
	SINT32 houghTres = 3;
	SINT32 cirCurRad;
	SINT32 sum;
	REAL32 maxRatio;
	SINT32 optix;
	SINT32 optiy;
	SINT32 TransResult[IMG_HEIGHT*IMG_WIDTH];
	SINT32 rad;
	lLineBytes = WIDTHBYTES(lWidth * 8);
	for(i = 0; i<lHeight; i++)
	{
		for(j = 0; j<lWidth; j++)
		{
			TransResult[i*lLineBytes+j] = 0;
		}
	}
	memcpy(lpNewDIBBits, lpDIBBits, lLineBytes*lHeight);
	for(cirCurRad = cirInRad; cirCurRad <= cirOutRad; cirCurRad++)
	{
		HoughtTransFixRadius(lpNewDIBBits, lWidth, lHeight, cirCurRad, TransResult, edgevalue, 0.3);
		for(i=0; i<lHeight; i++)
		{
			for(j=0; j<lWidth; j++)
			{
				if(TransResult[i*lLineBytes+j] >= houghTres)
				{
					sum = (SINT32)EdgeCirqueCorrMatchForPoint(lpNewDIBBits,lWidth, lHeight, cirCurRad, j, i, edgevalue, &num);
					ratio = (REAL32)sum/(REAL32)(num);
					if(ratio > maxRatio)
					{
						maxRatio = ratio;
						optix = j;
						optiy = i;
						rad = cirCurRad;
					}
				}
			}
		}
	}
	if(maxRatio < 0.3)
		return;
	cir->CenRow = optix;
	cir->CenCol = optiy;
	cir->Radius = rad;
	return;
}

struct returninteg { 
	unsigned char Sign; 
	float CurrentInteg; 
	unsigned int Control; 
}; 

struct returninteg AziFXPIOutput,HeiFXPIOutput;

struct integ { 
	float LastDev; 
	float CurrentDev; 
	float LastInteg; 
}; 

struct integ AziFXPIInput,HeiFXPIInput; 

float Ux2_PI ,Ux2_PI0 ,Ux2_D; 

#define AzimuthKP2 3 
#define AzimuthZERO 2047.0 
#define AzimuthKI2 0.005
#define AzimuthKD2 0

void Sys_AzimuthControl_PID() 
{ 
	float AziFXPIControl; 
	AziFXPIOutput.Sign = 0; 
	
	Ux2_PI=Ux2_PI0+AzimuthKP2*(AziFXPIInput.CurrentDev-AziFXPIInput.LastDev)+AzimuthKI2*(AziFXPIInput.CurrentDev+AziFXPIInput.LastDev); 
	
	Ux2_D=AzimuthKD2*(AziFXPIInput.CurrentDev-AziFXPIInput.LastDev);  
	
	AziFXPIControl =Ux2_PI + Ux2_D + AzimuthZERO;
	
	if( AziFXPIControl > 0 ) 
	{ 
		AziFXPIOutput.Sign = 1; 
	} 
	if( AziFXPIControl>4095.0 ) 
	{ 
		AziFXPIOutput.Control = 0xFFF; 
	} else if( AziFXPIControl<0.0 ) 
	{ 
		AziFXPIOutput.Control = 0; 
	} else { 
		AziFXPIOutput.Control = (unsigned short)AziFXPIControl; 
	} 
	
	AziFXPIInput.LastDev = AziFXPIInput.CurrentDev; Ux2_PI0=Ux2_PI; 
}

void sys_temp()
{
	Sys_AzimuthControl_PID();
}

int Ternary_expression(int a)
{
	int j = a;
	if(((j>0)?1:2) == 1)
	{
		return 1;
	}else
	{
		return 2;
	}
}

int test_for(int i)
{
	for(;;) {
		i++;
    }
	return i;

}

unsigned int NavInfoTrans(char cInfo[], char* cNavInfo, int iDev)
{
	unsigned int i = 0;
	char cDev = '0';
	int iInfoHead = 0;
	int iInfoEnd = 0;
	unsigned int iLen = 0;
	
	if(iDev == 0)
	{
		cDev = 'I';
	}else
	{
		cDev = 's';
	}
	
	for(i = 0; i < strlen(cNavInfo); i++)
	{
		if((cNavInfo[i] == cDev) && (cNavInfo[i + 1] == ':'))
		{
			iInfoHead = i + 2;
		}
		
		if((iInfoHead > 0) && (cNavInfo[i] == ';'))
		{
			iInfoEnd = i;
			iLen = iInfoEnd - iInfoHead;
			memcpy(cInfo, &cNavInfo[iInfoHead], iLen);
			cInfo[iLen] = '\0';
			break;
		}
	}
	
	return (iLen + 1);
}

int doubleTestdoubleTest(double a, double b, int g){
  double c = 0.0;
  double d = 0.0;
  
  int e = 0;
  int f = 0;
  
  c = a / g;
  e = a / b;
  
  if ( b == 2)
    e++;
  
  return c;
}

#define GL_LUMINANCE 3

unsigned int texFomat;


unsigned char* getGray(FILE *s, int size)
{
	unsigned char *grayData = NULL;
	int bread;

	if(NULL == s){
		return 0;
	}
	grayData = (unsigned char*)malloc(size);

	if(grayData == NULL){
		return 0;
	}
	bread = fread(grayData, sizeof(unsigned char), size, s);

	if(bread != size)
	{
		free(grayData);
			grayData = NULL;
		return 0;
	}else{
		grayData = (unsigned char*)malloc(size);
	}		

	texFomat = GL_LUMINANCE;

	return grayData;
}

int (*function_pointer[3])(int i);
/*
int func_p1(int kk);

int func_p2(int b);

int func_p3(int c);

function_pointer[0] = func_p1;
function_pointer[1] = func_p2;
function_pointer[3] = func_p3;
*/
int test_function_pointer_array(int k)
{
	int p;
	k = function_pointer[0](k);
	if(k > 0)
	{
		k = 1;
		return k;
	}else if(k == 0){
		k = -1;
		return k;
	}
	
	p = function_pointer[1](p);
	if(p == -1)
	{
		return p;
	}else{
		return function_pointer[2](function_pointer[0](k));
	}
}







