#include <iostream>
#include <math.h>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
#define maks 1000
#define dt 0.01
#define dim 2
#define g 9.81
#define r 1.0
#define m 1.0
#define Emin -r*g*m*0.8
#define ke 0.9
using namespace std;
double energy(double pos[], double vel[])
{
    double vsq=0;
    for (int i = 0; i < dim; i++)
    {
     vsq += vel[i]*vel[i];
    }
    return vsq*m/2-m*g*pos[0];

}
double distsq(double sus[])
{
    double distsq=0;
    for (int i = 0; i < dim; i++)
    {
        distsq += sus[i]*sus[i];
    }
    return distsq;
}
double  dot (double vec1[], double vec2[])
{
    double product=0;
    for (int i = 0; i < dim; i++)
    {
        product += vec1[i]*vec2[i];
    }
    return product;
}
void times (double scalar, double vec[], double output[])
{

    for (int i = 0; i < dim; i++)
    {
        output[i] = scalar*vec[i];
    }

}
void add(double vec1[], double vec2[])
{
    for (int i = 0; i < dim; i++)
        vec1[i] += vec2[i];
}

int main()
{
    cout<<Emin<<endl;
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
                //y  x
    double pos[]={0,0.1};
    double vel[]={0,0};
    double E=0;
    FILE* pisi;
    pisi = fopen("pos.txt","w");
int iter=0;

    while (energy(pos,vel)>Emin&&iter<maks)
    {
        //cout<<distsq(pos)<<endl;
        //cout<<pos[0]*pos[1]<<endl;


        vel[0] += g*dt;

        for (int i = 0; i < dim; i++)
        {
            pos[i] += vel[i]*dt;
            fprintf(pisi,"%lf \t ",pos[i]);


        }
        if (distsq(pos)>=r*r)
        {
            //najdi komponento v radialni smeri in jo obrn
            //         vektor vektor    vektor skalarni p    normiran vektor
            //v_bounce = v -    v     *  ( v    *              r   )
            //pozicijski vektor normiramo da se ne zagozdi
            times(r/sqrt(distsq(pos)),pos,pos);



            double scale=dot(pos,vel)/distsq(pos);
            double mideruslt[dim];
            //treba je 2x odšteti za popolni odboj
            times(-(1+sqrt(ke))*scale,pos,mideruslt);//verjetno izgubi samo radialno hitrost
            add(vel,mideruslt);
            //  times(0.9,vel,vel);//pomnožimo s tem da pomanjšamo energijo
            //std::cout<<"bounce "<<std::endl;
            // vel[0]=0;

        }
        fprintf(pisi,"%lf \t ",energy(pos,vel));

        fprintf(pisi,"\n ");

        iter++;


    }
    fclose(pisi);





    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}