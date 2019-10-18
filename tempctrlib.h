/* 
 * File:   tempctr.h
 */

#ifndef TEMPCTRLIB_H_
#define	TEMPCTRLIB_H_

#include <stdint.h>
#include "pid.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define PidCal(x)             IndPid(x)
  
typedef enum
{
    TEMP_HEAT_INIT=0,
    TEMP_HEAT_FULL = 1,
    TEMP_COOL,
    TEMP_HEAT,
    TEMP_AUTO,
    TEMP_BACKUP
} TEMP_CTR_STEP_Type;

typedef enum {
    TEMP_DIR_DOWN  =     0,
    TEMP_DIR_UP    =     1,
       
} TempDirType;

typedef enum {
    ADJ_LIMITE_MIN = 0, //����С������Χ���ڣ�ѹ��������Ƶ�����
    ADJ_LIMITE_MAX = 1, //����󲨶���Χ���ڣ�ѹ��������Ƶ�����
} TadjModeType;

//�����ж����ȼ� bCoolForce��ߣ�TempAir��֮���Զ��ж����

typedef struct
{
    uint8_t bTempManOn;                                  //�ֶ�������� //ÿ��ִ�к�����Զ������λ  //����ֶ�ֵ���׶λ�INIT,��΢�֣����ౣ��  Y
    uint8_t bManTempCoolReq;                             //�ⲿ����                                     Y
    uint16_t ManHeatOut;                                 //�ⲿ����                                     Y
    uint8_t WaveCnt;                                     //������� �ⲿֻ�� 
    int8_t StCoolEnd;                                    //�ⲿֻ��
    TEMP_CTR_STEP_Type  TempCtrStep;                     //�ⲿ��ʼ��Ϊ  TEMP_HEAT_FULL                 Y
    TadjModeType AdjMode;                                //����ģʽ                                     Y
    TempDirType bTempDir;                                //�ⲿֻ��
    TempDirType bTempDirLast;                            //�ⲿֻ��
    TempDirType bDelayEndDir;                            //�ⲿֻ��
    uint8_t TempKeepCnt;                                 //
    uint8_t TempDirKeepCnt;                              //
    uint8_t bCoolForce;                                  //ǿ�����䣬�����ж����ȼ���ã����ȹ̶���ȫ���Ƚ׶�
    uint8_t bTempCoolDis;                                //�¶�������ã�����TempAir,���0.5 //�ⲿֻ��
    uint8_t bCoolReq;                                    //�ⲿֻ��
    uint8_t bCoolReqLast;                                //�ⲿֻ�� 
    uint8_t bTempCoolReq;                                //�ⲿֻ��
    uint8_t bPulseCoolDelayEnd;                          //�ⲿֻ��
    int16_t TempCur;                                     //�ⲿ�趨           Y
    int16_t TempSet;                                     //�ⲿ�趨           Y
    int16_t TempForDir;                                  //�ⲿֻ��
    int16_t TempCoolDelayEnd;                            //�ⲿֻ��
    int16_t TempCoolEnd;                                 //�ⲿֻ��
    int16_t StCoolDelayEnd;                              //�ⲿֻ��
    int16_t TempOffsetCoolEn;                            //�ⲿ��ʼ��          Y        �����SET
    int16_t TempOffsetCoolDis;                           //�ⲿ��ʼ��          Y        �����SET
    int16_t TempOffsetHeatClose;                         //�ⲿ��ʼ��          Y        �����SET
    int16_t TempOffsetLimite;                            //�ⲿ�趨                     �����SET
    int16_t TempMax;                                     //�ⲿ��ʼ��Ϊ0x0000 Y
    int16_t TempMin;                                     //�ⲿ��ʼ��Ϊ0x7FFF Y
    int16_t TempLast;                                    //��ֹ��д
    int16_t TempSetLast;                                 //��ֹ��д
    int16_t TempAir;                                     //�����¶�                     �����趨ֵ���ڴ��¶Ƚ�ֹ����  Y
    int16_t CoolTimeSet;                                 //�ⲿֻ��
    int16_t CoolTimeCntOld;                              //�ⲿֻ��
    int16_t CoolTimeCnt;                                 //�ⲿֻ��
    int16_t CoolDelayTimeSv;                            //�ⲿ�趨           Y
    int16_t CoolDelayTimeCnt;                           //�ⲿ��ʼ�� Ϊ CoolDelayTimeSv
    int16_t NoTempCoolTimeCnt;                          //��¼��������֮��ļ������ʼ��Ϊ���ֵ
    int32_t HeatOut;                                    //�ⲿֻ��������ռ�ձ�
	PID_Type TempPid;                                    //�ⲿ�趨��ָ���¶�PID�������Զ�����PID�ڲ�����
    uint32_t TimeCnt;
} TEMP_CTR_PAR_Type;


void TempCtrAutoCool(TEMP_CTR_PAR_Type *TempCtrPar);    //��ͣʽ���Ƴ�����ѭ������,ÿ1s����һ��


#ifdef	__cplusplus
}
#endif



#endif	/* TEMPCTRLIB_H_ */

