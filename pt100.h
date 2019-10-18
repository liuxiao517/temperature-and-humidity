/* 
 * File:   templib.h

 */

#ifndef PT100_LIB_H_
#define	PT100_LIB_H_

#include "templib.h"

    

    typedef struct {
        float Res; //电阻值
        int32_t AdVal; //AD值
    } temp_sample_type;
    
	typedef struct {
        uint8_t Err;
        uint8_t sample_nums; //采样点数量
        uint8_t bCFEn;
        int32_t AdcVal;
        //修正
        int16_t Pb;
        int16_t Pk;
        //范围
        float TempLimiteL; //测温下限
        float TempLimiteH; //测温上限
        //输出
        float Flt;
        float TempReal;   //
        float TempCtr;    //
        float TempDisp;   //
        
        //整数化系数
        float temp_ctr_coef;
        float temp_disp_coef;
        int16_t iTempCtr;
        int16_t iTempDisp;
        //采样点
        temp_sample_type Sample[4];   //采样点
        
    } pt100_type;


#endif	/* TEMPLIB_H_ */

