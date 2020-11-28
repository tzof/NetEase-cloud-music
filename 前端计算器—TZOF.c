// 11.9 前端计算器——tzof
#include <stdio.h>
    float w=0;        //总宽度
    float h=0;        //总高度
    float vw=0;       //宽度百分比
    float vh=0;       //高度百分比
    float wpx=0;      //元素宽度
    float hpx=0;      //元素高度
    float p_x=0;       //存放vw vh转换的中间变量
    char ch='S';      //重启开始
    char zh='Z';      //开启计算器类型

    // float pt=0;       //pt打印单位
// 进入计算器类型函数
void how(void)
{
    printf("\n输入需要进入的计算器：\nwpx/hpx转vw/vh输入：V\nvw/vh转wpx/hpx输入：P\nvw转vh输入：H\nvh转vw输入：W\n");
    scanf(" %c",&zh);
    getchar();
}
// 输入视图的总宽度,总高度
void px(void)
{
    printf("\n输入总宽度 总高度：");
    scanf("%f %f",&w,&h);
    printf("\n");
}
// 重启计算器函数
void clean(void)
{
    printf("输入R选择其他类型计算器或者重新输入宽高，输入其他任意键开启计算器：");
    getchar();
    scanf("%c",&ch);
    printf("\n\n\n");
}
// 输入元素的宽度和高度
void p_v_scan(void){
    printf("输入元素的宽度 高度：");
    scanf("%f %f",&wpx,&hpx);
    printf("\n");
}
// 输出vw,vh比例转换结果
void p_v_print(float w,float h, float vw,float vh)
{
    printf("W:%.1fpx总宽度,H:%.1fpx总高度\n",w,h);
    printf("wpx：%.1fpx,hpx：%.1fpx\n",wpx,hpx);
    printf("vw：%.3fvw\nvh：%.3fvh\n\n",vw,vh);
}
// 输入元素的vw和vh
void v_p_scan()
{
    printf("输入元素的vw vh：");
    scanf("%f %f",&vw,&vh);
    printf("\n");
}
// 输出vw,vh转换px结果
void v_p_print(float w, float h, float vw, float vh)
{
    printf("W:%.1fpx总宽度,H:%.1fpx总高度\n",w,h);
    printf("vw:%.3f,vh:%.3f\n",vw,vh);
    printf("wpx：%.1fpx\nhpx：%.1fpx\n\n",wpx,hpx);
}
// 输入vw
void vw_vh_scan(void)
{
    printf("输入元素的vw：");
    scanf("%f",&vw);
    printf("\n");
}
// 输出vw转vh的结果
void vw_vh_print(float w, float h, float vw, float vh)
{
    printf("W:%.1fpx总宽度,H:%.1fpx总高度\n",w,h);
    printf("元素大小:%.1fpx\n",wpx);
    printf("vw:%.3f=vh:%.3f\n\n",vw,vh);
}
// 输入vh
void vh_vw_scan(void)
{
    printf("输入元素的vh：");
    scanf("%f",&vh);
    printf("\n");
}
// 输出vw转vh的结果
void vh_vw_print(float w, float h, float vh, float vw)
{
    printf("W:%.1fpx总宽度,H:%.1fpx总高度\n",w,h);
    printf("元素大小:%.1fpx\n",hpx);
    printf("vh:%.3f=vw:%.3f\n\n",vh,vw);
}
// vw,vh比例换算函数
void p_v(float w,float h,float wpx,float hpx)
{
    vw=wpx/w*100;
    vh=hpx/h*100;
    p_v_print(w,h,vw,vh);
}
// vw,vh转换px换算函数
void v_p(float w,float h,float vw,float vh)
{
    wpx=w*(vw/100);
    hpx=h*(vh/100);
    v_p_print(w,h,vw,vh);
}
// vw转vh计算函数
void vw_vh(float w,float h, float vw)
{
    p_x=w*vw/100;
    vh=p_x/h*100;
    wpx=w*(vw/100);
    vw_vh_print(w,h,vw,vh);
}
// vh转vw计算函数
void vh_vw(float w,float h, float vh)
{
    p_x=h*vh/100;
    vw=p_x/w*100;
    hpx=h*(vh/100);
    vh_vw_print(w,h,vh,vw);
}
int main(void)
{
    printf("\n前端计算器——TZOF\n\n");
    while(1)
    {
        how();
        if(zh!='V' && zh!='P' && zh!='H' && zh!='W')
        {
            printf("输入错误请重新输入\n");
            ch='R';
            zh='S';
        }
        else if(zh=='V' || zh=='P' || zh=='H' || zh=='W')
        {
            px();
        }
        while(ch!='R')
        {
            while(ch!='R' && zh=='V')
            {
                p_v_scan();
                p_v(w,h,wpx,hpx);
                clean();
            }
            while(ch!='R' && zh=='P')
            {
                v_p_scan();                
                v_p(w,h,vw,vh);
                clean();
            }
            while(ch!='R' && zh=='H')
            {
                vw_vh_scan();
                vw_vh(w,h,vw);
                clean();
            }
            while(ch!='R' && zh=='W')
            {
                vh_vw_scan();
                vh_vw(w,h,vh);
                clean();
            }
        }
        ch='S'; 
        zh='S';
    }
    
    getchar();
    return 0;
}