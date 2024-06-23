/**
  ******************************************************************************
  * @file    py32m0xx.h
  * @brief   CMSIS PY32M0xx Device Peripheral Access Layer Header File.
  * @version v1.0.0
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 Puya Semiconductor Co.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by Puya under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup py32m0xx
  * @{
  */

#ifndef __PY32M0XX_H
#define __PY32M0XX_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** @addtogroup Library_configuration_section
  * @{
  */

/**
  * @brief PY32 Family
  */
#if !defined  (PY32M0)
#define PY32M0
#endif /* PY32M0 */

/* Uncomment the line below according to the target PY32 device used in your
   application
  */

#if !defined (PY32M010x5) && !defined (PY32M020x6) && !defined (PY32M030x8) && \
    !defined (PY32M070x6) && !defined (PY32M070x8) && !defined (PY32M070x9) && !defined (PY32M070xB) && \
    !defined (PY32M070Cx6) && !defined (PY32M070Cx8) && !defined (PY32M070Cx9) && !defined (PY32M070CxB)
/* #define PY32M010x5 */  /*!< PY32M010x5 Devices (PY32M010x5 microcontrollers where the Flash memory is 24 Kbytes) */
/* #define PY32M020x6 */  /*!< PY32M020x6 Devices (PY32M020x6 microcontrollers where the Flash memory is 32 Kbytes) */
/* #define PY32M030x8 */  /*!< PY32M030x8 Devices (PY32M030x8 microcontrollers where the Flash memory is 64 Kbytes) */
#endif

/*  Tip: To avoid modifying this file each time you need to switch between these
        devices, you can define the device in your toolchain compiler preprocessor.
  */
#if (defined(PY32M010x5))
#define PY32M010PRE
#elif (defined(PY32M020x6))
#define PY32M020PRE
#elif (defined(PY32M030x8))
#define PY32M030PRE
#elif (defined(PY32M070x6)) || (defined(PY32M070x8)) || (defined(PY32M070x9)) || (defined(PY32M070xB))
#define PY32M070PRE
#elif (defined(PY32M070Cx6)) || (defined(PY32M070Cx8)) || (defined(PY32M070Cx9)) || (defined(PY32M070CxB))
#define PY32M070CPRE
#endif

/**
  * @brief CMSIS Device version number V1.0.0
  */
#define __PY32M0_DEVICE_VERSION_MAIN   (0x01) /*!< [31:24] main version */
#define __PY32M0_DEVICE_VERSION_SUB1   (0x00) /*!< [23:16] sub1 version */
#define __PY32M0_DEVICE_VERSION_SUB2   (0x00) /*!< [15:8]  sub2 version */
#define __PY32M0_DEVICE_VERSION_RC     (0x00) /*!< [7:0]  release candidate */
#define __PY32M0_DEVICE_VERSION        ((__PY32M0_DEVICE_VERSION_MAIN << 24)\
                                        |(__PY32M0_DEVICE_VERSION_SUB1 << 16)\
                                        |(__PY32M0_DEVICE_VERSION_SUB2 << 8 )\
                                        |(__PY32M0_DEVICE_VERSION_RC))

/**
  * @}
  */

/** @addtogroup Device_Included
  * @{
  */
#if defined(PY32M010x5)
#include "py32m010x5.h"
#elif defined(PY32M020x6)
#include "py32m020x6.h"
#elif defined(PY32M030x8)
#include "py32m030x8.h"
#elif defined(PY32M070x6)
#include "py32m070x6.h"
#elif defined(PY32M070x8)
#include "py32m070x8.h"
#elif defined(PY32M070x9)
#include "py32m070x9.h"
#elif defined(PY32M070xB)
#include "py32m070xB.h"
#elif defined(PY32M070Cx6)
#include "py32m070cx6.h"
#elif defined(PY32M070Cx8)
#include "py32m070cx8.h"
#elif defined(PY32M070Cx9)
#include "py32m070cx9.h"
#elif defined(PY32M070CxB)
#include "py32m070cxB.h"
#else
#error "Please select first the target PY32M0xx device used in your application (in py32m0xx.h file)"
#endif

/**
  * @}
  */

/** @addtogroup Exported_types
  * @{
  */
typedef enum
{
  RESET = 0,
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum
{
  DISABLE = 0,
  ENABLE = !DISABLE
} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum 
{
  SUCCESS = 0U,
  ERROR = !SUCCESS
} ErrorStatus;

/**
  * @}
  */


/** @addtogroup Exported_macros
  * @{
  */
#define SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define READ_REG(REG)         ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

#define POSITION_VAL(VAL)     (__CLZ(__RBIT(VAL)))

/* Use of interrupt control for register exclusive access */
/* Atomic 32-bit register access macro to set one or several bits */
#define ATOMIC_SET_BIT(REG, BIT)                             \
  do {                                                       \
    uint32_t primask;                                        \
    primask = __get_PRIMASK();                               \
    __set_PRIMASK(1);                                        \
    SET_BIT((REG), (BIT));                                   \
    __set_PRIMASK(primask);                                  \
  } while(0)

/* Atomic 32-bit register access macro to clear one or several bits */
#define ATOMIC_CLEAR_BIT(REG, BIT)                           \
  do {                                                       \
    uint32_t primask;                                        \
    primask = __get_PRIMASK();                               \
    __set_PRIMASK(1);                                        \
    CLEAR_BIT((REG), (BIT));                                 \
    __set_PRIMASK(primask);                                  \
  } while(0)

/* Atomic 32-bit register access macro to clear and set one or several bits */
#define ATOMIC_MODIFY_REG(REG, CLEARMSK, SETMASK)            \
  do {                                                       \
    uint32_t primask;                                        \
    primask = __get_PRIMASK();                               \
    __set_PRIMASK(1);                                        \
    MODIFY_REG((REG), (CLEARMSK), (SETMASK));                \
    __set_PRIMASK(primask);                                  \
  } while(0)

/* Atomic 16-bit register access macro to set one or several bits */
#define ATOMIC_SETH_BIT(REG, BIT) ATOMIC_SET_BIT(REG, BIT)                                   \

/* Atomic 16-bit register access macro to clear one or several bits */
#define ATOMIC_CLEARH_BIT(REG, BIT) ATOMIC_CLEAR_BIT(REG, BIT)                               \

/* Atomic 16-bit register access macro to clear and set one or several bits */
#define ATOMIC_MODIFYH_REG(REG, CLEARMSK, SETMASK) ATOMIC_MODIFY_REG(REG, CLEARMSK, SETMASK) \

#define HW32_REG(ADDRESS)     ( * ((volatile unsigned           int * )(ADDRESS)))

#define HW16_REG(ADDRESS)     ( * ((volatile unsigned short     int * )(ADDRESS)))

#define HW8_REG(ADDRESS)      ( * ((volatile unsigned          char * )(ADDRESS)))

#define M32(ADDRESS)          HW32_REG(ADDRESS)

#define M16(ADDRESS)          HW16_REG(ADDRESS)

#define M8(ADDRESS)           HW8_REG(ADDRESS)

/**
  * @}
  */
#if !defined  (USE_HAL_DRIVER)
/**
 * @brief Comment the line below if you will not use the peripherals drivers.
   In this case, these drivers will not be included and the application code will
   be based on direct access to peripherals registers
   */
/*#define USE_HAL_DRIVER */
#endif /* USE_HAL_DRIVER */

#if defined (USE_HAL_DRIVER)
 #include "py32m0xx_hal.h"
#endif /* USE_HAL_DRIVER */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __PY32M0XX_H */
/**
  * @}
  */

/**
  * @}
  */


/************************ (C) COPYRIGHT Puya *****END OF FILE******************/

