/**HEADER********************************************************************
*
* Copyright (c) 2008 Freescale Semiconductor;
* All Rights Reserved
*
***************************************************************************
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*
**************************************************************************
*
* $FileName: adc_mk70.h$
* $Version : 3.8.0.2$
* $Date    : Dec-2-2011$
*
* Comments:
*
*   CPU specific ADC driver header file
*
*END************************************************************************/

#ifndef __adc_mk70_h__
#define __adc_mk70_h__


#define ADC_HAS_16BIT_RESOLUTION           1
#define ADC_HAS_DIFFERENTIAL_CHANNELS      1
#define ADC_HAS_PGA                        1


#define ADC0_SOURCE_ADPM0       (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(0) | ADC_SOURCE_DIFF)
#define ADC0_SOURCE_ADPM1       (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(1) | ADC_SOURCE_DIFF)
#define ADC0_SOURCE_ADPM2       (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(2) | ADC_SOURCE_DIFF)
#define ADC0_SOURCE_ADPM3       (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(3) | ADC_SOURCE_DIFF)
#define ADC0_SOURCE_AD0         (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(0))
#define ADC0_SOURCE_AD1         (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(1))
#define ADC0_SOURCE_AD2         (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(2))
#define ADC0_SOURCE_AD3         (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(3))
#define ADC0_SOURCE_AD4A        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_A | ADC_SOURCE_CHANNEL(4))
#define ADC0_SOURCE_AD5A        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_A | ADC_SOURCE_CHANNEL(4))
#define ADC0_SOURCE_AD6A        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_A | ADC_SOURCE_CHANNEL(4))
#define ADC0_SOURCE_AD7A        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_A | ADC_SOURCE_CHANNEL(4))
#define ADC0_SOURCE_AD4B        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_B | ADC_SOURCE_CHANNEL(4))
#define ADC0_SOURCE_AD5B        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_B | ADC_SOURCE_CHANNEL(5))
#define ADC0_SOURCE_AD6B        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_B | ADC_SOURCE_CHANNEL(6))
#define ADC0_SOURCE_AD7B        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_B | ADC_SOURCE_CHANNEL(7))
#define ADC0_SOURCE_AD8         (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(8))
#define ADC0_SOURCE_AD9         (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(9))
#define ADC0_SOURCE_AD10        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(10))
#define ADC0_SOURCE_AD11        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(11))
#define ADC0_SOURCE_AD12        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(12))
#define ADC0_SOURCE_AD13        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(13))
#define ADC0_SOURCE_AD14        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(14))
#define ADC0_SOURCE_AD15        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(15))
#define ADC0_SOURCE_AD16        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(16))
#define ADC0_SOURCE_AD17        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(17))
#define ADC0_SOURCE_AD18        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(18))
#define ADC0_SOURCE_AD19        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(19))
#define ADC0_SOURCE_AD20        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(20))
#define ADC0_SOURCE_AD21        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(21))
#define ADC0_SOURCE_AD22        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(22))
#define ADC0_SOURCE_AD23        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(23))
#define ADC0_SOURCE_AD24        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(24))
#define ADC0_SOURCE_AD25        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(25))
#define ADC0_SOURCE_AD26        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(26))
#define ADC0_SOURCE_AD27        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(27))
#define ADC0_SOURCE_AD28        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(28))
#define ADC0_SOURCE_AD29        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(29))
#define ADC0_SOURCE_AD30        (ADC_SOURCE_MODULE(1) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(30))



#define ADC0_SOURCE_DAC0            (ADC0_SOURCE_AD23)
#define ADC0_SOURCE_TEMP            (ADC0_SOURCE_AD26)
#define ADC0_SOURCE_TEMP_DIFF       (ADC0_SOURCE_AD26 | ADC_SOURCE_DIFF)
#define ADC0_SOURCE_BANDGAP         (ADC0_SOURCE_AD27)
#define ADC0_SOURCE_BANDGAP_DIFF    (ADC0_SOURCE_AD27 | ADC_SOURCE_DIFF)
#define ADC0_SOURCE_VREFH           (ADC0_SOURCE_AD29)
#define ADC0_SOURCE_VREFH_DIFF      (ADC0_SOURCE_AD29 | ADC_SOURCE_DIFF)
#define ADC0_SOURCE_VREFL           (ADC0_SOURCE_AD30)

#define ADC1_SOURCE_ADPM0       (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(0) | ADC_SOURCE_DIFF)
#define ADC1_SOURCE_ADPM1       (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(1) | ADC_SOURCE_DIFF)
#define ADC1_SOURCE_ADPM2       (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(2) | ADC_SOURCE_DIFF)
#define ADC1_SOURCE_ADPM3       (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(3) | ADC_SOURCE_DIFF)
#define ADC1_SOURCE_AD0         (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(0))
#define ADC1_SOURCE_AD1         (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(1))
#define ADC1_SOURCE_AD2         (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(2))
#define ADC1_SOURCE_AD3         (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(3))
#define ADC1_SOURCE_AD4A        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_A | ADC_SOURCE_CHANNEL(4))
#define ADC1_SOURCE_AD5A        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_A | ADC_SOURCE_CHANNEL(5))
#define ADC1_SOURCE_AD6A        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_A | ADC_SOURCE_CHANNEL(6))
#define ADC1_SOURCE_AD7A        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_A | ADC_SOURCE_CHANNEL(7))
#define ADC1_SOURCE_AD4B        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_B | ADC_SOURCE_CHANNEL(4))
#define ADC1_SOURCE_AD5B        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_B | ADC_SOURCE_CHANNEL(5))
#define ADC1_SOURCE_AD6B        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_B | ADC_SOURCE_CHANNEL(6))
#define ADC1_SOURCE_AD7B        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_B | ADC_SOURCE_CHANNEL(7))
#define ADC1_SOURCE_AD8         (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(8))
#define ADC1_SOURCE_AD9         (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(9))
#define ADC1_SOURCE_AD10        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(10))
#define ADC1_SOURCE_AD11        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(11))
#define ADC1_SOURCE_AD12        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(12))
#define ADC1_SOURCE_AD13        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(13))
#define ADC1_SOURCE_AD14        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(14))
#define ADC1_SOURCE_AD15        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(15))
#define ADC1_SOURCE_AD16        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(16))
#define ADC1_SOURCE_AD17        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(17))
#define ADC1_SOURCE_AD18        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(18))
#define ADC1_SOURCE_AD19        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(19))
#define ADC1_SOURCE_AD20        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(20))
#define ADC1_SOURCE_AD21        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(21))
#define ADC1_SOURCE_AD22        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(22))
#define ADC1_SOURCE_AD23        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(23))
#define ADC1_SOURCE_AD24        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(24))
#define ADC1_SOURCE_AD25        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(25))
#define ADC1_SOURCE_AD26        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(26))
#define ADC1_SOURCE_AD27        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(27))
#define ADC1_SOURCE_AD28        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(26))
#define ADC1_SOURCE_AD29        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(29))
#define ADC1_SOURCE_AD30        (ADC_SOURCE_MODULE(2) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(30))

#define ADC1_SOURCE_VREF            (ADC1_SOURCE_AD18)

#define ADC1_SOURCE_DAC1            (ADC1_SOURCE_AD23)
#define ADC1_SOURCE_TEMP            (ADC1_SOURCE_AD26)
#define ADC1_SOURCE_TEMP_DIFF       (ADC1_SOURCE_AD26 | ADC_SOURCE_DIFF)
#define ADC1_SOURCE_BANDGAP         (ADC1_SOURCE_AD27)
#define ADC1_SOURCE_BANDGAP_DIFF    (ADC1_SOURCE_AD27 | ADC_SOURCE_DIFF)
#define ADC1_SOURCE_VREFH           (ADC1_SOURCE_AD29)
#define ADC1_SOURCE_VREFH_DIFF      (ADC1_SOURCE_AD29 | ADC_SOURCE_DIFF)
#define ADC1_SOURCE_VREFL           (ADC1_SOURCE_AD30)

#define ADC2_SOURCE_ADPM0       (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(0) | ADC_SOURCE_DIFF)
#define ADC2_SOURCE_ADPM1       (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(1) | ADC_SOURCE_DIFF)
#define ADC2_SOURCE_ADPM2       (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(2) | ADC_SOURCE_DIFF)
#define ADC2_SOURCE_ADPM3       (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(3) | ADC_SOURCE_DIFF)
#define ADC2_SOURCE_AD0         (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(0))
#define ADC2_SOURCE_AD1         (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(1))
#define ADC2_SOURCE_AD2         (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(2))
#define ADC2_SOURCE_AD3         (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(3))
#define ADC2_SOURCE_AD4A        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_A | ADC_SOURCE_CHANNEL(4))
#define ADC2_SOURCE_AD5A        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_A | ADC_SOURCE_CHANNEL(5))
#define ADC2_SOURCE_AD6A        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_A | ADC_SOURCE_CHANNEL(6))
#define ADC2_SOURCE_AD7A        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_A | ADC_SOURCE_CHANNEL(7))
#define ADC2_SOURCE_AD4B        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_B | ADC_SOURCE_CHANNEL(4))
#define ADC2_SOURCE_AD5B        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_B | ADC_SOURCE_CHANNEL(5))
#define ADC2_SOURCE_AD6B        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_B | ADC_SOURCE_CHANNEL(6))
#define ADC2_SOURCE_AD7B        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_B | ADC_SOURCE_CHANNEL(7))
#define ADC2_SOURCE_AD8         (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(8))
#define ADC2_SOURCE_AD9         (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(9))
#define ADC2_SOURCE_AD10        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(10))
#define ADC2_SOURCE_AD11        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(11))
#define ADC2_SOURCE_AD12        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(12))
#define ADC2_SOURCE_AD13        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(13))
#define ADC2_SOURCE_AD14        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(14))
#define ADC2_SOURCE_AD15        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(15))
#define ADC2_SOURCE_AD16        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(16))
#define ADC2_SOURCE_AD17        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(17))
#define ADC2_SOURCE_AD18        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(18))
#define ADC2_SOURCE_AD19        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(19))
#define ADC2_SOURCE_AD20        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(20))
#define ADC2_SOURCE_AD21        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(21))
#define ADC2_SOURCE_AD22        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(22))
#define ADC2_SOURCE_AD23        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(23))
#define ADC2_SOURCE_AD24        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(24))
#define ADC2_SOURCE_AD25        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(25))
#define ADC2_SOURCE_AD26        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(26))
#define ADC2_SOURCE_AD27        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(27))
#define ADC2_SOURCE_AD28        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(26))
#define ADC2_SOURCE_AD29        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(29))
#define ADC2_SOURCE_AD30        (ADC_SOURCE_MODULE(3) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(30))


#define ADC2_SOURCE_VREF            (ADC2_SOURCE_AD18)

#define ADC2_SOURCE_DAC1            (ADC2_SOURCE_AD23)
#define ADC2_SOURCE_TEMP            (ADC2_SOURCE_AD26)
#define ADC2_SOURCE_TEMP_DIFF       (ADC2_SOURCE_AD26 | ADC_SOURCE_DIFF)
#define ADC2_SOURCE_BANDGAP         (ADC2_SOURCE_AD27)
#define ADC2_SOURCE_BANDGAP_DIFF    (ADC2_SOURCE_AD27 | ADC_SOURCE_DIFF)
#define ADC2_SOURCE_VREFH           (ADC2_SOURCE_AD29)
#define ADC2_SOURCE_VREFH_DIFF      (ADC2_SOURCE_AD29 | ADC_SOURCE_DIFF)
#define ADC2_SOURCE_VREFL           (ADC2_SOURCE_AD30)


#define ADC3_SOURCE_ADPM0       (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(0) | ADC_SOURCE_DIFF)
#define ADC3_SOURCE_ADPM1       (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(1) | ADC_SOURCE_DIFF)
#define ADC3_SOURCE_ADPM2       (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(2) | ADC_SOURCE_DIFF)
#define ADC3_SOURCE_ADPM3       (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(3) | ADC_SOURCE_DIFF)
#define ADC3_SOURCE_AD0         (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(0))
#define ADC3_SOURCE_AD1         (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(1))
#define ADC3_SOURCE_AD2         (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(2))
#define ADC3_SOURCE_AD3         (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(3))
#define ADC3_SOURCE_AD4A        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_A | ADC_SOURCE_CHANNEL(4))
#define ADC3_SOURCE_AD5A        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_A | ADC_SOURCE_CHANNEL(5))
#define ADC3_SOURCE_AD6A        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_A | ADC_SOURCE_CHANNEL(6))
#define ADC3_SOURCE_AD7A        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_A | ADC_SOURCE_CHANNEL(7))
#define ADC3_SOURCE_AD4B        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_B | ADC_SOURCE_CHANNEL(4))
#define ADC3_SOURCE_AD5B        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_B | ADC_SOURCE_CHANNEL(5))
#define ADC3_SOURCE_AD6B        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_B | ADC_SOURCE_CHANNEL(6))
#define ADC3_SOURCE_AD7B        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_B | ADC_SOURCE_CHANNEL(7))
#define ADC3_SOURCE_AD8         (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(8))
#define ADC3_SOURCE_AD9         (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(9))
#define ADC3_SOURCE_AD10        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(10))
#define ADC3_SOURCE_AD11        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(11))
#define ADC3_SOURCE_AD12        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(12))
#define ADC3_SOURCE_AD13        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(13))
#define ADC3_SOURCE_AD14        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(14))
#define ADC3_SOURCE_AD15        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(15))
#define ADC3_SOURCE_AD16        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(16))
#define ADC3_SOURCE_AD17        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(17))
#define ADC3_SOURCE_AD18        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(18))
#define ADC3_SOURCE_AD19        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(19))
#define ADC3_SOURCE_AD20        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(20))
#define ADC3_SOURCE_AD21        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(21))
#define ADC3_SOURCE_AD22        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(22))
#define ADC3_SOURCE_AD23        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(23))
#define ADC3_SOURCE_AD24        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(24))
#define ADC3_SOURCE_AD25        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(25))
#define ADC3_SOURCE_AD26        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(26))
#define ADC3_SOURCE_AD27        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(27))
#define ADC3_SOURCE_AD28        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(26))
#define ADC3_SOURCE_AD29        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(29))
#define ADC3_SOURCE_AD30        (ADC_SOURCE_MODULE(4) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(30))


#define ADC3_SOURCE_VREF            (ADC3_SOURCE_AD18)

#define ADC3_SOURCE_DAC1            (ADC3_SOURCE_AD23)
#define ADC3_SOURCE_TEMP            (ADC3_SOURCE_AD26)
#define ADC3_SOURCE_TEMP_DIFF       (ADC3_SOURCE_AD26 | ADC_SOURCE_DIFF)
#define ADC3_SOURCE_BANDGAP         (ADC3_SOURCE_AD27)
#define ADC3_SOURCE_BANDGAP_DIFF    (ADC3_SOURCE_AD27 | ADC_SOURCE_DIFF)
#define ADC3_SOURCE_VREFH           (ADC3_SOURCE_AD29)
#define ADC3_SOURCE_VREFH_DIFF      (ADC3_SOURCE_AD29 | ADC_SOURCE_DIFF)
#define ADC3_SOURCE_VREFL           (ADC3_SOURCE_AD30)


#endif /* __adc_mk70_h__ */
