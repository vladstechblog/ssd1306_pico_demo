#ifndef D_UptimePresenter_H
#define D_UptimePresenter_H

#define DATA_BUFFER_SIZE 128
#define UPTIME_MAX 6000 //10 hours
#define TIMESTAMP_LENGTH 8

void UptimePresenter_Create(void);
void UptimePresenter_Destroy(void);
unsigned char* UptimePresenter_GetData(void);
uint8_t* UptimePresenter_MapAsciiToFont(char);
void UptimePresenter_FormatTimestamp(int, char*);

#endif  /* D_UptimePresenter_H */
