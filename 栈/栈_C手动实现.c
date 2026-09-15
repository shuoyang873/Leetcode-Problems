#include<stdio.h>
#include<stdlib.h>

#define ERR -1
#define OVERFLOW -2
#define OK 0

typedef int Status;
typedef int Selement;
#define STACK_INIT_SIZE 100
#define STACK_INCR_ELEMENT 10

typedef struct Sqstack{
	Selement* base;
	Selement* top;
	int stack_size;
}Sqstack;

Status InitStack(Sqstack *s) {
	s->base = (Selement*)malloc(STACK_INIT_SIZE * sizeof(Selement));
	if (!s->base) {
		return ERR;
	}
	s->stack_size = STACK_INIT_SIZE;
	s->top = s->base;
	return OK;
}

Status Get_top(Sqstack* s,Selement *val) {
	if (s->top == s->base) {
		return ERR;
	}
	*val = *(s->top-1);
	return OK;
}

Status Push(Sqstack* s,Selement v) {
	if (s->top - s->base >= s->stack_size) {
		s->base = (Selement*)realloc(s->base,(STACK_INCR_ELEMENT+s->stack_size) * sizeof(Selement));
		if (!s->base)return OVERFLOW;
		s->top = s->base + s->stack_size;
		s->stack_size += STACK_INCR_ELEMENT;
	}
	*s->top++ = v;
	return OK;
}

Status Pop(Sqstack* s,Selement*val) {
	if (s->base == s->top) {
		return ERR;
	}
	*val = *(--s->top);
	return OK;
}

int main() {

}