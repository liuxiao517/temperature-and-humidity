/* 
 * File:   tempctr.h
 */

#ifndef HUMITEMPCTRLIB_H_
#define	HUMITEMPCTRLIB_H_

#include <stdint.h>
#include "tempctrlib.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define HUMI_AUTO_BACK_MAX                           1

//#define COOL_TIME_SET_EN

typedef enum
{
    HUMI_INC_INIT = 0,
    HUMI_INC_FULL,
    HUMI_CLR,
    HUMI_INC,
    HUMI_AUTO,
    HUMI_BACKUP
} HUMI_CTR_STEP_Type;

typedef enum {
    HUMI_DIR_DOWN  =     0,
    HUMI_DIR_UP    =     1,  
} HumiDirType;

typedef enum {
    HUMI_TEMP_CTR_MODE_NOCOOL_NOCLR=0,
    HUMI_TEMP_CTR_MODE_COOL=1,
    HUMI_TEMP_CTR_MODE_HUMICLR=2,    
} CtrModeType;

typedef struct
{
    TadjModeType AdjMode;                                //����ģʽ       
    uint8_t bTempManOn;                                  //�¶��ֶ�����           Y
    uint8_t bManTempCoolReq;                             //                       Y
    uint16_t ManHeatOut;                                 //                       Y
    uint8_t bHumiManOn;                                  //ʪ���ֶ�����           Y
    uint8_t bManHumiCoolReq;                             //                       Y
    uint16_t ManHumiOut;                                 //                       Y
    uint8_t bCoolForce;                                  //ǿ�ƿ�����             Y
    CtrModeType CtrMode;                                 //�ⲿ��ʼ�� 0          IY
    CtrModeType CtrModeOld;                              //�ⲿ��ʼ�� 0          IY
    TEMP_CTR_STEP_Type  TempCtrStep;                     //�ⲿ��ʼ��ΪTEMP_HEAT_FULL     IY
    TEMP_CTR_STEP_Type  TempCtrStepOld; 
    TempDirType bTempDir;                                //�ⲿֻ�� X
    TempDirType bTempDirLast;                            //�ⲿֻ�� X
    TempDirType bDelayEndDir;                            //�ⲿֻ�� X
    uint8_t TempKeepCnt;                                 //�ⲿֻ�� X
    uint8_t TempDirKeepCnt;                              //�ⲿֻ�� X
    uint8_t WaveCnt;                                     //������� �ⲿ��ʼ��0  IY
    uint8_t SubAdjCnt;                                   //�ⲿ��ʼ��0           IY
    uint8_t bTempCoolDis;                                //�¶�������ã�����TempAir,���0.5 X
    uint8_t bCoolReq;                                    //�ⲿֻ��           X
    uint8_t bCoolReqLast;                                //�ⲿֻ��           X
    uint8_t bTempCoolReq;                                //�ⲿֻ��           X
    uint8_t bTempAdjDone;                                //�ⲿֻ��           X
    uint8_t bPulseCoolDelayEnd;                          //�ⲿֻ��
    int16_t TempCur;                                     //�ⲿ�趨           Y
    int16_t TempSet;                                     //�ⲿ�趨           Y
    int16_t TempAtCoolStart;                             //�ⲿֻ��           X
    int16_t TempForDir;                                  //�ⲿֻ��           X
    int16_t TempCoolDelayEnd;                            //�ⲿֻ��           X
    int16_t TempCoolEnd;                                 //�ⲿֻ��           X
    int16_t StCoolDelayEnd;                              //�ⲿֻ��
    int16_t TempOffsetCoolEn;                            //�ⲿ��ʼ��         IY        �����SET
    int16_t TempOffsetCoolDis;                           //�ⲿ��ʼ��         IY        �����SET
    int16_t TempOffsetHeatClose;                         //�ⲿ��ʼ��         IY        �����SET
    int16_t TempOffsetLimite;                            //�ⲿ�趨           Y         �����SET
    int16_t TempMax;                                     //�ⲿ��ʼ��Ϊ0x0000 IY
    int16_t TempMin;                                     //�ⲿ��ʼ��Ϊ0x7FFF IY
    int16_t TempMaxOld;                                  //�ⲿ��ʼ��Ϊ0x0000 IY
    int16_t TempMinOld;                                  //�ⲿ��ʼ��Ϊ0x7FFF IY
    int16_t TempLast;                                    //��ֹ��д
    int16_t TempSetLast;                                 //��ֹ��д
    int16_t TempAir;                                     //�����ж��Ƿ���������     Y
    int16_t CoolDelayTimeSv;                            //�ⲿ�趨                  Y
    int16_t CoolDelayTimeCnt;                           //�ϵ��ʼ��Ϊ CoolDelayTimeSv ֮���ֹ�޸� IIY
    int16_t NoTempCoolTimeCnt;                          //��¼��������֮��ļ������ʼ��Ϊ���ֵ    IY
    int16_t TempCtrSvAtCoolOffset;                      //�ⲿֻ��           X
    int32_t HeatOut;                                    //�ⲿֻ��������ռ�ձ� X
	PID_Type TempPid;                                   //�ⲿ�趨��ָ���¶�PID�������Զ�����PID�ڲ�����

    //�����ʱ
    int16_t CoolTimeCnt;                                 //ʵʱ����ʱ�� X
    int16_t CoolTimeCntOld;                              //Update at Cool-End X
    int16_t CoolCloseTimeCnt;                            //������ʱ�� X
    int16_t CoolTimeSet;                                 // ����ʱ��X
    //ʪ�ȿ��Ʋ���
    uint8_t StHumiCtrEn;                                 //ʪ�ȿ���ʹ�� Y
    uint8_t StHumiAdjEn;                                 //���ڿ���     X
    uint8_t bCoolClrCloseByTemp;                         //�¶�ԭ���³�ʪ�ر� X
    HUMI_CTR_STEP_Type  HumiCtrStep;                     //�ⲿ��ʼ��ΪHUMI_INC_FULL   X
    HUMI_CTR_STEP_Type  HumiCtrStepOld;
    HumiDirType bHumiDir;                                //�ⲿֻ��           X
    HumiDirType bHumiDirLast;                            //�ⲿֻ��           X
    HumiDirType bDeayEndHumiDir;                         //�ⲿֻ��           X
    uint8_t bHumiCoolReq;                                //�ⲿֻ��           X
    uint8_t bHumiAdjDone;                                //�ⲿֻ��           X
    uint8_t HumiKeepCnt;                                 //�ⲿֻ��           X
    uint8_t HumiDirKeepCnt;                              //�ⲿֻ��           X
    int16_t HumiForDir;                                  //�ⲿֻ��           X
    int16_t HumiCur;                                     //�ⲿ�趨           Y
    int16_t HumiSet;                                     //�ⲿ�趨           Y
    int16_t HumiSetLast;                                 //�ⲿֻ��           X
    int16_t HumiCtrTemp;                                 //�ⲿ�趨           IY
    int16_t HumiClrOpenPoint;                            //�ⲿ�趨//�趨ֵ���ڸ�ֵ����ʪ   Y
    int16_t HumiIncClose;                                //�ⲿ�趨           IY
    int16_t HumiClrEn;                                   //�ⲿ�趨           IY
    int16_t HumiClrDis;                                  //�ⲿ�趨           IY
    int16_t HumiCtrLimiteL;                              //�ⲿ�趨           Y //���ڲ�����С����ģ�ͣ��˲�����Ч
    int16_t HumiCtrLimiteH;                              //�ⲿ�趨           Y //
    int16_t HumiCtrLimiteCenter;                         //�����������ĵ�
    int16_t HumiCtrLimiteAverage;                        //��������ƽ��ֵ
    int16_t HumiDelayEnd;                                //�ⲿֻ��           X
    int16_t HumiClrEnd;                                  //�ⲿֻ��           X
    int16_t StHumiClrDelayEnd;                           //�ⲿֻ��           X
    int16_t HumiMax;                                     //�ⲿ��ʼ��Ϊ0x0000 IY
    int16_t HumiMin;                                     //�ⲿ��ʼ��Ϊ0x7FFF IY 
    int16_t HumiMaxOld;                                  //�ⲿ��ʼ��Ϊ0x0000 IY
    int16_t HumiMinOld;                                  //�ⲿ��ʼ��Ϊ0x7FFF IY
    int16_t NoHumiCoolTimeCnt;                           //�ⲿ�趨           Y
    int16_t HumiCtrSvAtCoolOffset;                       //�ⲿֻ��           X
    int32_t HumiOut;                                     //�ⲿֻ������ʪռ�ձ�
    PID_Type HumiPid;                                    //�ⲿ��ʼ��

    uint32_t TimeCnt;
    uint32_t StepTimeCnt;
} HUMITEMP_CTR_PAR_Type;


void HumiTempCtr(HUMITEMP_CTR_PAR_Type *HTempCtrPar);   
void HT_Control(HUMITEMP_CTR_PAR_Type *CtrPar);

#ifdef	__cplusplus
}
#endif



#endif	/* HUMITEMPCTRLIB_H_ */

