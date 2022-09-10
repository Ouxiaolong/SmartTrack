/**
  ******************************************************************************
  * @file                task.c
  * @author              BruceOu
  * @version             V1.0
  * @date                2022-08-30
  * @blog                https://blog.bruceou.cn/
  * @Official Accounts   嵌入式实验楼
  * @brief
  ******************************************************************************
  */
#include "task.h"
#include "gui_guider.h"
#include "events_init.h"
#include <time.h>
#include <stdio.h>

extern lv_ui guider_ui;

st_aht10 aht10;

int rt_hw_aht10_port(void)
{
    struct rt_sensor_config cfg;
    cfg.intf.dev_name  = AHT10_I2C_BUS;
    cfg.intf.user_data = (void *)AHT10_I2C_ADDR;
    rt_hw_aht10_init("aht10", &cfg);
    return RT_EOK;
}
INIT_COMPONENT_EXPORT(rt_hw_aht10_port);


// AHT10温湿度采集
#include "aht10.h"

/* 定义一个温湿度采集线程句柄结构体指针 */
static rt_thread_t aht10_thread = RT_NULL;

/* 温湿度采集线程入口函数*/
static void aht10_thread_entry(void *parameter)
{
    aht10_device_t dev;
    float humidity, temperature;

    rt_hw_aht10_port();
    dev = aht10_init(AHT10_I2C_BUS);
    if (dev == RT_NULL)
    {
        rt_kprintf(" The sensor initializes failure");
    }

    while (1)
    {
        /* read humidity 采集湿度 */
        humidity = aht10_read_humidity(dev);
        /* read temperature 采集温度 */
        temperature = aht10_read_temperature(dev);
        aht10.humidity = humidity;
        aht10.temperature = temperature;

        /* former is integer and behind is decimal */
        
		rt_kprintf("humidity: %d.%d %%, temperature: %d.%d \n", (int)humidity, (int)(humidity * 10) % 10, (int)temperature, (int)(temperature * 10) % 10);

        rt_thread_mdelay(1000);
    }
}

int aht10_app_init(void)
{
    /* 创建温湿度采集线程*/
    aht10_thread = rt_thread_create("aht10 thread",     /* 线程的名称 */
                                aht10_thread_entry, /* 线程入口函数 */
                                RT_NULL,            /* 线程入口函数的参数   */
                                1024,                /* 线程栈大小，单位是字节  */
                                25,                 /* 线程的优先级，数值越小优先级越高*/
                                10);                /* 线程的时间片大小 */
    /* 如果获得线程控制块，启动这个线程 */
    if (aht10_thread != RT_NULL)
        rt_thread_startup(aht10_thread);
    else
        rt_kprintf("aht10 thread create failure !!! \n");

    return RT_EOK;
}

/* 导出到 msh 命令列表中 */
//MSH_CMD_EXPORT(aht10_app_init, aht110 thread);

INIT_APP_EXPORT(aht10_app_init);


static rt_thread_t lvgl_thread = RT_NULL;


static void aht10_event(lv_ui *ui)
{
    char str_temp[16];

    memset(str_temp,0,sizeof(str_temp));
	
    // 把浮点数转换为字符串，存放在str_temp中。
    //sprintf(str_temp,"%.1fC",aht10.temperature);
	sprintf(str_temp,"%dC",lv_rand( 25, 30));
	
    lv_label_set_text(ui->screen1_label_temp, str_temp);

    //sprintf(str_temp,"%.1f",aht10.humidity);
    sprintf(str_temp,"%d%%",lv_rand( 50, 55));
    lv_label_set_text(ui->screen1_label_hum, str_temp);

    sprintf(str_temp,"%d",lv_rand( 30, 50));
    lv_label_set_text(ui->screen1_label_speed_data, str_temp);
	
    sprintf(str_temp,"%dC",lv_rand( 0, 360));
    lv_label_set_text(ui->screen1_label_pitch_data, str_temp);

    sprintf(str_temp,"%dC",lv_rand( 0, 180));
    lv_label_set_text(ui->screen1_label_roll_data, str_temp);

    sprintf(str_temp,"%dC",lv_rand( 0, 90));
    lv_label_set_text(ui->screen1_label_yaw_data, str_temp);

}

static void lvgl_thread_entry(void *parameter)
{

    while (1)
    {
		if((aht10.humidity - 1) > 0)
		{
            aht10_event(&guider_ui);
        }
        rt_thread_mdelay(500);
    }
}

int lvgl_update_init(void)
{
    /* 创建线程*/
    lvgl_thread = rt_thread_create("lvgl thread",     /* 线程的名称 */
                                lvgl_thread_entry, /* 线程入口函数 */
                                RT_NULL,            /* 线程入口函数的参数   */
                                1024,                /* 线程栈大小，单位是字节  */
                                20,                 /* 线程的优先级，数值越小优先级越高*/
                                10);                /* 线程的时间片大小 */
    /* 如果获得线程控制块，启动这个线程 */
    if (lvgl_thread != RT_NULL)
        rt_thread_startup(lvgl_thread);
    else
        rt_kprintf("lvgl thread create failure !!! \n");

    return RT_EOK;
}

/* 导出到 msh 命令列表中 */
//MSH_CMD_EXPORT(lvgl_update_init, lvgl data thread);
INIT_APP_EXPORT(lvgl_update_init);
