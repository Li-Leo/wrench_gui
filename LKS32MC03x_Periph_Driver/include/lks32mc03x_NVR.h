#ifndef __NVR_H__
#define __NVR_H__

// Read_Trim建议在初始化的过程中调用
// Read_Trim会关闭全局中断
unsigned int Read_Trim(unsigned int addr);

#endif
