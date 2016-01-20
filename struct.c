

typedef struct double_int_short_char{
  double d;
  int i;
  short s;
  char c;
} disc;

typedef struct pointer_int_short_char{
  void *p;
  int i;
  short s;
  char c;
} pisc;

typedef struct int_short_char{
  int i;
  short s;
  char c;
} isc;

typedef struct short_int_char{
  short s;
  int i;
  char c;
} sic;

typedef struct short_int_char_double{
  short s;
  int i;
  char c;
  double d;
} sicd;

typedef struct int_short_char_double{
  int i;
  short s;
  char c;
  double d;
} iscd;

typedef struct padding_double{
  short s1;
  int i1;
  char c1;
  // 7 bytes tot
  double d1;
  short s2;
  int i2;
  char c2;
  
} sicdsic;

typedef struct padding_struct{
  sic sic1;
  // 7 bytes tot
  double d1;
  sic sic2;
} sicdsic_t;







typedef struct char_1{
  char a;
  char b;
  char c;
  char d;
} cccc;

typedef struct char_2{
  char a;
  char b;
  char c;
  char d;
  char e;
} ccccc;
