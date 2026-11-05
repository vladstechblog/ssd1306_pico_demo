#ifndef D_UptimePresenter_H
#define D_UptimePresenter_H

#define DATA_BUFFER_SIZE ((unsigned int) ((128 * 64) / 8))
#define UPTIME_MAX 6000 //10 hours
#define TIMESTAMP_LENGTH 8
#define DISPLAY_LINE_SIZE 8
#define DISPLAY_LINE_BYTES (DISPLAY_LINE_SIZE * 8)

void UptimePresenter_Create(void);
void UptimePresenter_Destroy(void);
unsigned char* UptimePresenter_GetData(void);
uint8_t* UptimePresenter_MapAsciiToFont(char);
void UptimePresenter_FormatTimestamp(uint16_t, char*);
void UptimePresenter_UpdateUptime(uint16_t);

#endif  /* D_UptimePresenter_H */
