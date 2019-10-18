/* 
 * File:   templib.h

 */

#ifndef PT100_LIB_H_
#define	PT100_LIB_H_

#include "templib.h"

    

    typedef struct {
        float Res; //����ֵ
        int32_t AdVal; //ADֵ
    } temp_sample_type;
    
	typedef struct {
        uint8_t Err;
        uint8_t sample_nums; //����������
        uint8_t bCFEn;
        int32_t AdcVal;
        //����
        int16_t Pb;
        int16_t Pk;
        //��Χ
        float TempLimiteL; //��������
        float TempLimiteH; //��������
        //���
        float Flt;
        float TempReal;   //
        float TempCtr;    //
        float TempDisp;   //
        
        //������ϵ��
        float temp_ctr_coef;
        float temp_disp_coef;
        int16_t iTempCtr;
        int16_t iTempDisp;
        //������
        temp_sample_type Sample[4];   //������
        
    } pt100_type;


#endif	/* TEMPLIB_H_ */

