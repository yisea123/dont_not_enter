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
* $FileName: adc_mcf51qm.h$
* $Version : 3.8.0.2$
* $Date    : Dec-2-2011$
*
* Comments:
*
*   CPU specific ADC driver header file
*
*END************************************************************************/

#ifndef __adc_mcf51qm_h__
#define __adc_mcf51qm_h__


#define ADC_HAS_16BIT_RESOLUTION           1
#define ADC_HAS_DIFFERENTIAL_CHANNELS      1
#define ADC_HAS_PGA                        0

#define ADC0_SOURCE_ADPM0   (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(0))
#define ADC0_SOURCE_ADPM1   (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(1))
#define ADC0_SOURCE_ADPM2   (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(2))
#define ADC0_SOURCE_ADPM3   (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(3))
#define ADC0_SOURCE_AD0     (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(0))
#define ADC0_SOURCE_AD1     (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(1))
#define ADC0_SOURCE_AD2     (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(2))
#define ADC0_SOURCE_AD3     (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(3))
#define ADC0_SOURCE_AD4     (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(4))
#define ADC0_SOURCE_AD5     (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(5))
#define ADC0_SOURCE_AD6     (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(6))
#define ADC0_SOURCE_AD7     (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(7))
#define ADC0_SOURCE_AD8     (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(8))
#define ADC0_SOURCE_AD9     (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(9))
#define ADC0_SOURCE_AD10    (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(10))
#define ADC0_SOURCE_AD11    (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(11))
#define ADC0_SOURCE_AD12    (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(12))
#define ADC0_SOURCE_AD13    (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(13))
#define ADC0_SOURCE_AD14    (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(14))
#define ADC0_SOURCE_AD15    (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(15))
#define ADC0_SOURCE_AD16    (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(16))
#define ADC0_SOURCE_AD17    (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(17))
#define ADC0_SOURCE_AD18    (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(18))
#define ADC0_SOURCE_AD19    (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(19))
#define ADC0_SOURCE_AD20    (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(20))
#define ADC0_SOURCE_AD21    (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(21))
#define ADC0_SOURCE_AD22    (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(22))
#define ADC0_SOURCE_AD23    (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(23))

#define ADC_SOURCE_PMTEMP   (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(26))
#define ADC_SOURCE_TEMP     (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(26))
#define ADC_SOURCE_PMBG     (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(27))
#define ADC_SOURCE_BGL      (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(27))
#define ADC_SOURCE_PMVREFH  (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(29))
#define ADC_SOURCE_VREFH    (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(29))
#define ADC_SOURCE_VREFL    (ADC_SOURCE_MODULE(0) | ADC_SOURCE_MUXSEL_X | ADC_SOURCE_CHANNEL(30))



#endif /* __adc_mcf51qm_h__ */
