/* 
 * File:   PIDdevice.h
 * v0.404
 */

#ifndef PIDDEVICE_H
#define	PIDDEVICE_H

#include "stdint.h"

#ifdef	__cplusplus
extern "C" {
#endif	
	
#ifdef   _PID_MODULE_
#define  PID_EXT
#else
#define  PID_EXT  extern
#endif

#define Q_15_VAL_1_0F                            (0x8000UL) //Q.15��ʽ������ 1
#define Q_15_VAL_0_5F                            (0x4000UL) //Q.15��ʽ������ 0.5
#define Q_15_VAL_0_25F                           (0x2000UL) //Q.15��ʽ������ 0.25
#define Q_15_VAL_0_125F                          (0x1000UL) //Q.15��ʽ������ 0.125
#define Q_15_VAL_NV1_0F                          (-0x8000L) //Q.15��ʽ������ 1
#define Q_15_VAL_NV0_5F                          (-0x4000L) //Q.15��ʽ������ 0.5
#define Q_15_VAL_NV0_25F                         (-0x2000L) //Q.15��ʽ������ 0.25
#define Q_15_VAL_NV0_125F                        (-0x1000L) //Q.15��ʽ������ 0.125

#define KI_INCRE_LIMITE_ERR                    2     // ���ڿ����ֱ����ж�

//������������
#define PID_MODE_SIN                           0    
#define PID_MODE_LSIN                          1     //line+sin
#define PID_MODE_LINE                          2
#define PID_MODE_LCOS                          3     //line+cos
#define PID_MODE_COS                           4     

//������
#define TEMP_PID_P_POS     0
#define TEMP_PID_I_POS     1
#define TEMP_PID_D_POS     2
#define TEMP_PID_AR_POS    3
#define TEMP_PID_T_POS     4


typedef enum{ 
    DWK_NONE  = 0,
    DWK_DIR_UP  ,//�仯��������ʱ����[-P~+P]->[1~(1-c)]
    DWK_DIR_DOWN ,//�仯��������ʱ����[-P~+P]->[(1-c)~1]
    DWK_P_DIR_DC ,//����仯��ǿ�������� [-P~+P]->[(1+c)~1]->[2~1] ������仯������������[-P~+P]->[1~(1-c)]->[1~0]
    DWK_P_DIR_DN ,//����仯������������ [-P~+P]->[(1-c)~1]->[0~1] ������仯��ǿ��������[-P~+P]->[1~(1+c)]->[1~2]
} DV_WEAK_TYPE;

typedef enum {
    DZ_MD_NOR=0,
    DZ_MD_NEV=1, //��С���趨ֵ
    DZ_MD_PST=2, //�������趨ֵ
} DEAD_ZONE_MODE_TYPE;

	typedef  struct
	{
        int8_t  bDir;    
        DV_WEAK_TYPE DvWeakType;//�ⲿ����  
        DEAD_ZONE_MODE_TYPE DeadZoneMode;        
		uint16_t Kt;            //�ⲿ���£������update
		uint16_t KtCnt;         //�ⲿ����
        uint16_t Cycle;         //�ⲿ���� //��������
        
		uint16_t P;  //�ⲿ���£������update
        uint16_t I;  //�ⲿ���£������update
        uint16_t D;  //�ⲿ���£������update
		uint16_t AR; //�ⲿ���£������update
		int32_t OutMax;//�ⲿ���£������update
		int32_t OutMin;//�ⲿ���£������update
        
		int32_t Out;                            //������    
		int32_t IoutMax;                     //����б�ʼ��㣬��б��ʱȡ IoutMax_Line_H
        int32_t IoutMax_Line_L;             //�ⲿ����    �����޷���������    ����ֵ
        int32_t IoutMax_Line_H;             //�ⲿ����    �����޷���������    ����ֵ 
        int32_t IoutLimite_line_svL;           //IoutLimite_line_svH>IoutLimite_line_svLʱ��Ч�����Է�Χ
        int32_t IoutLimite_line_svH;     //�ⲿ����
        int32_t q15_DirAdjZone;      //�ⲿ���� ,Q.15
        int32_t q15_PvForDir;      //Q.15
        
        float AdjOut;                 //PID���ֵ
        float OutCoef;                //0~1.0f//�ⲿ����
        float OutCoefFlt;             //0~0.99//�ⲿ����  
        float DeadZone;               //�ⲿ����
		float DFt;
        float DvWeak;         //P�������ֵ���ⲿ����
        float DvWeakMax;      //�������ֵ���ⲿ����
		float Sv;             //�ⲿ����
		float Pv;             //�ⲿ����
		float Pvn1;
        float Pvn2;
        float Pvd;
		float Kp;
		float Ki;
		float Kd;   
		float uk; 
        float outFac;   //������
        float outFac_offs; 
		float dv;                         
	} PID_Type;

	
	typedef  struct
	{
		uint8_t  CtrDir;                //0:�������     1���������
		uint8_t  State;                 //0:����������   FF:����������
		uint16_t RisingTimeCnt;
		uint16_t FallingTimeCnt;
		uint16_t AutoSetTimeCnt;
        uint16_t P;
		uint16_t I;
        uint16_t D;
		float  MeasureMin;
		float  MeasureMax;
        float  CtrZone;                 //����ز��
        float  IdCoef;                  //΢�ֻ��ֱ���
		PID_Type *Pid;
        void(*ParSave)(void);           //����Pid����������������ⲿ���溯��
	
	} PID_AUTO_SET_Type;
	
    typedef struct
    {
        //timer
        uint16_t kt;
        uint16_t kt_cnt;
        //input
        int32_t q15_sv;
        int32_t q15_pv;
        int32_t q15_dead_zone;
        //pid set
        int32_t q15_p;  //0~(32768 << 15)
        int16_t i;
        int16_t d;
        //middle value
        int32_t q15_kp;
        int32_t q15_ki;
        int32_t q15_kd;
        int32_t q15_dft;
        int32_t q15_dv;
        //process value
        int32_t q15_ival;
        int32_t q15_imax;
        int32_t q15_pv_old;
        //limite
        int32_t q15_max;
        int32_t q15_min;
        //out
        int32_t q15_out;
        int16_t out;
    } q15_pid_type;
    
	void SitePid(PID_Type* pid);

	void PidClr(PID_Type* pid);//clear (dv,uk)    set(OutCoef = 1)
    void PidDvClr(PID_Type* pid); //clear dv
	void PidPvSet(PID_Type* pid,float Pv); //Set pv
    void PidSvSet(PID_Type* pid,float Sv); //Set Sv
    
    void LcosPid(PID_Type* pid);
    void CosPid(PID_Type* pid);
    void SinPid(PID_Type* pid);
    void ComPid(PID_Type* pid);
	void IndPid(PID_Type* pid);
    
    void PidOutWeaken(PID_Type* pid, float Coef);
    void PidUpdate(PID_Type* pid,uint16_t *ParTab,int32_t DutyMin,int32_t DutyMax);
    void PidIoutSet(PID_Type *pid, int16_t svL, int16_t svH, int16_t i_min_per, uint16_t i_max_per);//svΪ�趨ֵ��perΪ����ٷֱ�
    
	uint8_t PidAutoSet(PID_AUTO_SET_Type *AutoSetPar);
	void PidAutoSetStart(PID_Type *Pid, PID_AUTO_SET_Type *AutoSetPar);
	void PidAutoSetExit(PID_AUTO_SET_Type *AutoSetPar);
	void PidAutoSetCal(PID_AUTO_SET_Type *AutoSetPar);
	
    
    int32_t q15_pid_update(q15_pid_type *pid);
    int32_t q15_pid_cal(q15_pid_type *pid);
    void q15_pid_clr(q15_pid_type *pid);
    void q15_pid_dv_clr(q15_pid_type *pid);
    
    
#undef PID_EXT

#ifdef	__cplusplus
}
#endif

#endif	/* PIDDEVICE_H */
