#ifndef D_UptimePresenter_Spy_H
#define D_UptimePresenter_Spy_H

void UptimePresenter_Spy_Create(void);
void UptimePresenter_Spy_Destroy(void);
uint16_t UptimePresenter_Spy_GetTimeStamp(void);
void UptimePresenter_UpdateUptime(uint16_t);

#endif  /* D_FakeUptimePresenter_Spy_H */
