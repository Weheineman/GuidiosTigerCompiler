#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>



typedef struct {
  long n; /*cantidad de caracteres*/
  char s[0];
} *string;


string consts[256];
string empty;

string allocString(long n);

int main()
{
	int i;
	empty = allocString(0);
	empty->n = 0;
	for(i=0;i<256;i++)
	{	
		consts[i] = allocString(1);
		consts[i]->n = 1;
		consts[i]->s[0] = i;
	}
	return _tigermain(0 /* static link!? */);
}


long * _initArray(long size, long init)
{long i;
 long *a = (long *)malloc(size*sizeof(long));
 for(i=0;i<size;i++) a[i]=init;
 return a;
}


long _checkindex(long *a, long i)
{
  if(i < 0 || i >= a[-1]){
    fprintf(stderr, "Indice fuera de rango %ld %ld \n", a[-1] , i);
    exit(-1);
   }
   else return a[i];
}



long * _allocRecord(long ctos, ...)
{
  long *p,*q;
  va_list va; 
  q = p = malloc(sizeof(long)*ctos);
  va_start(va,ctos);
  while(ctos--){
    *q++ = va_arg(va,long);
  }
  
  va_end(va);
  return p;
}

void _checkNil(long l)
{
  if(l==0){
    fprintf (stderr, "Nil!!\n");
    exit(-1);
  }
}

string allocString(long n)
{
  string s = malloc(sizeof(*s) + n);
  return s;
}

long _stringCompare(string s1, string s2)
{
  unsigned i,tope;
  
  int masCorto = s1->n < s2->n;
  tope = masCorto?s1->n : s2->n;
  
  for(i=0; i<tope; i++)
    if(s1->s[i] != s2->s[i]) return s1->s[i] - s2->s[i];
  
  return s1->n == s2->n ? 0 : masCorto? -1 : 1;
}

void print(string s)
{
  int i;
  for(i=0; i<s->n; i++)
    putchar(s->s[i]);
}

void flush()
{
  fflush(stdout);
}

int ord(string s)
{
 if (s->n==0) return -1;
 else return s->s[0];
}

string chr(long i)
{
	if (i<0 || i>=256) 
	{
		printf("chr(%ld) out of range\n",i); 
		exit(1);
	}
	return consts[i];
}

long size(string s)
{ 
 return s->n;
}

string substring(string s, long first, long n)
{
	if (first<0 || first+n>s->n)
	{
		printf("substring([%ld],%ld,%ld) out of range\n",s->n,first,n);
		exit(1);
    }
	if (n==1) return consts[s->s[first]];
	{
		string t =allocString(n);
		int i;
		t->n=n;
		for(i=0;i<n;i++) t->s[i]=s->s[first+i];
		return  t;
	}
}

string concat(string a, string b)
{
	if (a->n==0) return b;
	else if (b->n==0) return a;	
	else {
		int i, n=a->n+b->n;
		string t = allocString(n);
		t->n=n;
		for (i = 0; i < a->n ; i++)
			t->s[i]=a->s[i];
		for(i=0;i<b->n;i++)
			t->s[i+a->n]=b->s[i];
		return t;
	}
}

int not(int i)
{ 
	return !i;
}

#undef getchar

string getstr()
{
	int i=getc(stdin);
	if (i==EOF) return empty;
	else return consts[i];
}

/*
void _exit(long i)
{
		exit(i);
}
*/
