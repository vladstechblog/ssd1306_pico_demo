#ifndef D_Timer_H
#define D_Timer_H

#define MAX_SECONDS 5999

void Timer_Create(int* coutner);
void Timer_Destroy(void);
int* Timer_GetCounterPointer(void);
void Timer_Tick(void);

#endif  /* Timer_H */
