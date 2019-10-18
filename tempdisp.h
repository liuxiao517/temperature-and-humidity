/* 
 * File:   tempctr.h
 */

#ifndef TEMPDISPLIB_H_
#define	TEMPDISPLIB_H_

#include <stdint.h>


#ifdef	__cplusplus
extern "C" {
#endif

#define FOLLOW_LIST_SIZE          32
typedef struct {
    int16_t  SetPoint;      //�ⲿ����      YYY
	int16_t  CurPoint;      //�ⲿ����      YYY
    
    uint8_t  bFollowSt;     //�Ƿ������٣��ⲿ���� + �ڲ���⵽�趨=�����Զ���ʼ + �ڲ���⵽�趨ֵ�仯�Զ��˳�      YYY
    uint8_t  bCalPulse;     //��������    ���ⲿ����      YYY
    uint8_t  KeepTimeSv;    //�����׶α���ʱ�䣬�����ݼ�¼���������ɴ���FOLLOW_LIST_SIZE-2���ⲿ����      YYY
    uint16_t FollowQuitPeriod; //�˸������ڣ��ⲿ����      YYY
    uint16_t FollowEntryPeriod; //���������ڣ��ⲿ����      YYY
    uint16_t PulseAutoCnt;  //�ڲ�����
	int16_t  FollowVal;     //�ڲ�����
	int16_t  FollowValMaxSet;  //�ⲿ����      YYY
    int16_t  FollowValMaxCur;  //�ڲ�
    int16_t  DispVal;          //�ڲ��������
    int16_t  SetPointLast;      //
    int16_t  FollowValList[FOLLOW_LIST_SIZE];//�ڲ�����
    uint16_t DataListPeriod;    //���ݼ�¼����      YYY
    uint16_t FollowQuitDelayCnt;//�ڲ�����
    uint16_t FollowQuitDelaySv; //�ⲿ����      YYY
    
} disp_flt_fixed_Type;

typedef struct {
    uint8_t bFollowSt;      //YYY
    uint8_t  bCalPulse;      //YYY
    int16_t ValSv;         //YYY
    int16_t ValPv;            //YYY
    int16_t ValDisp;
    int16_t ValFollow;
    int16_t  FollowValMaxSet;  //�ⲿ����  //YYY
    int16_t  FollowValMaxCur;
    uint8_t Coef;  //YYY
    uint8_t  KeepTimeSv; //�����׶α���ʱ�䣬�����ݼ�¼���������ɴ���FOLLOW_LIST_SIZE-2���ⲿ����  //YYY
    int16_t ValSvLast;
    int16_t  FollowValList[FOLLOW_LIST_SIZE];//�ڲ�����
    uint16_t DataListPeriod;    //���ݼ�¼����  //YYY
    uint16_t PulseAutoCnt;  //�ڲ�����
    uint16_t FollowQuitPeriod; //�˸������ڣ��ⲿ����  //YYY
    uint16_t FollowEntryPeriod; //���������ڣ��ⲿ����  //YYY
    uint16_t FollowQuitDelayCnt;//�ڲ�����
    uint16_t FollowQuitDelaySv; //�ⲿ����  //YYY
} disp_flt_dync_Type;

void DispFltFiexd(disp_flt_fixed_Type *DispObj);
void DispFltDync(disp_flt_dync_Type *DispObj);

#ifdef	__cplusplus
}
#endif



#endif	/* TEMPDISPLIB_H_ */

