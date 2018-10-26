/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 */

#include <rtdevice.h>
#include <rtthread.h>
#include "drv_pwm.h"
#ifdef BSP_USING_PWM1
static struct rt_device_pwm pwm1;
#endif

static rt_err_t drv_pwm_control(struct rt_device_pwm *device, int cmd, void *arg);
static struct rt_pwm_ops drv_ops =
    {
        drv_pwm_control
    };

static rt_err_t drv_pwm_enable(void *user_data, struct rt_pwm_configuration *configuration, rt_bool_t enable)
{
    /* start/stop pwm_x chanel_x output */
    return RT_EOK;
}

static rt_err_t drv_pwm_get(void *user_data, struct rt_pwm_configuration *configuration)
{
    /* get pluse ,period ... */
    return RT_EOK;
}
static rt_err_t drv_pwm_set(void *user_data, struct rt_pwm_configuration *configuration)
{
    /* set pluse ,period ... */
    return RT_EOK;
}

static rt_err_t drv_pwm_control(struct rt_device_pwm *device, int cmd, void *arg)
{
    struct rt_pwm_configuration *configuration = (struct rt_pwm_configuration *)arg;
    void *user_data = device->parent.user_data;

    switch (cmd)
    {
    case PWM_CMD_ENABLE:
        return drv_pwm_enable(user_data, configuration, RT_TRUE);
    case PWM_CMD_DISABLE:
        return drv_pwm_enable(user_data, configuration, RT_FALSE);
    case PWM_CMD_SET:
        return drv_pwm_set(user_data, configuration);
    case PWM_CMD_GET:
        return drv_pwm_get(user_data, configuration);
    default:
        return RT_EINVAL;
    }
}

int drv_pwm_init(void)
{
    /* register pwm */
#ifdef BSP_USING_PWM1
    rt_device_pwm_register(&pwm1, "pwm1", &drv_ops, &user_data);
#endif
    return 0;
}
INIT_DEVICE_EXPORT(drv_pwm_init);

