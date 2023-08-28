#ifndef SERIAL_H_
#define SERIAL_H_
// 上面的宏定义是为了防止重复引用这个头文件而引起的重定义错误


int serial_send(int *msg_temp);
int serial_get(void);

#endif