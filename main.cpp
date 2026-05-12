#include <iostream>
#include <math.h>


int makslen= 10000;
double maks= 1000;
double dt= 0.1;
#define dim 2
#define g 9.81
#define r 1.0
#define m 1.0
#define Emin -r*g*m*0.999
#define ke 0.9
#define drawSparse ((int)ceil(maks/makslen))
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

void pipe()
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
            //          fprintf(pisi,"%lf \t ",pos[i]);


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
            times(-(2)*scale,pos,mideruslt);//verjetno izgubi samo radialno hitrost
            add(vel,mideruslt);
            times(sqrt(ke),vel,vel);//pomnožimo s tem da pomanjšamo energijo
            //std::cout<<"bounce "<<std::endl;
            // vel[0]=0;

        }


        if (iter%drawSparse==0||distsq(pos)>=r*r)
        {
            for (int i = 0; i < dim; i++)
            {
                //    pos[i] += vel[i]*dt;
                fprintf(pisi,"%lf \t ",pos[i]);


            }
            fprintf(pisi,"%lf \t ",energy(pos,vel));

            fprintf(pisi,"\n ");
        }


        iter++;


    }
    fclose(pisi);



}

void pipeBAD()
{
    cout<<Emin<<endl;
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    //y  x
    double pos[]={0,0.1};
    double vel[]={0,0};
    double E=0;
    FILE* pisi;
    pisi = fopen("posBAD.txt","w");
    int iter=0;

    while (energy(pos,vel)>Emin&&iter<maks)
    {
        //cout<<distsq(pos)<<endl;
        //cout<<pos[0]*pos[1]<<endl;

        for (int i = 0; i < dim; i++)
        {
            pos[i] += vel[i]*dt;
            //          fprintf(pisi,"%lf \t ",pos[i]);


        }

        vel[0] += g*dt;

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
            times(-(2)*scale,pos,mideruslt);//verjetno izgubi samo radialno hitrost
            add(vel,mideruslt);
            times(sqrt(ke),vel,vel);//pomnožimo s tem da pomanjšamo energijo
            //std::cout<<"bounce "<<std::endl;
            // vel[0]=0;

        }


        if (iter%drawSparse==0||distsq(pos)>=r*r)
        {
            for (int i = 0; i < dim; i++)
            {
                //    pos[i] += vel[i]*dt;
                fprintf(pisi,"%lf \t ",pos[i]);


            }
            fprintf(pisi,"%lf \t ",energy(pos,vel));

            fprintf(pisi,"\n ");
        }


        iter++;


    }
    fclose(pisi);



}

void timetrap(int factor, int depth)
{
    for (int i=0; i<depth; i++)
    {

        cout<<Emin<<endl;
        // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
        //y  x
        double pos[]={0,0.1};
        double vel[]={0,0};
        double E=0;
       // string fil= "pos.txt";
        FILE* pisi;
        pisi = fopen("Ineeddalongsting.txt"+i,"w");
        int iter=0;

        while (energy(pos,vel)>Emin&&iter<maks)
        {
            //cout<<distsq(pos)<<endl;
            //cout<<pos[0]*pos[1]<<endl;


            vel[0] += g*dt;

            for (int i = 0; i < dim; i++)
            {
                pos[i] += vel[i]*dt;
                //          fprintf(pisi,"%lf \t ",pos[i]);


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
                times(-(2)*scale,pos,mideruslt);//verjetno izgubi samo radialno hitrost
                add(vel,mideruslt);
                times(sqrt(ke),vel,vel);//pomnožimo s tem da pomanjšamo energijo
                //std::cout<<"bounce "<<std::endl;
                // vel[0]=0;

            }


            if (iter%drawSparse==0||distsq(pos)>=r*r)
            {
                for (int i = 0; i < dim; i++)
                {
                    //    pos[i] += vel[i]*dt;
                    fprintf(pisi,"%lf \t ",pos[i]);


                }
                fprintf(pisi,"%lf \t ",energy(pos,vel));

                fprintf(pisi,"\n ");
            }


            iter++;


        }
        fclose(pisi);
        dt/=factor;
        maks*=factor;


    }

}
void chaos(int factor, int depth)
{
    for (int i=0; i<depth; i++)
    {

        cout<<Emin<<endl;
        // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
        //y  x
        double pos[]={0,0.1};
        double vel[]={0,0};
        double E=0;
       // string fil= "pos.txt";
        FILE* pisi;
        pisi = fopen("Ineeddalongsting.txt"+i,"w");
        int iter=0;

        while (energy(pos,vel)>Emin&&iter<maks)
        {
            //cout<<distsq(pos)<<endl;
            //cout<<pos[0]*pos[1]<<endl;


            vel[0] += g*dt;

            for (int i = 0; i < dim; i++)
            {
                pos[i] += vel[i]*dt;
                //          fprintf(pisi,"%lf \t ",pos[i]);


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
                times(-(2)*scale,pos,mideruslt);//verjetno izgubi samo radialno hitrost
                add(vel,mideruslt);
                times(sqrt(ke),vel,vel);//pomnožimo s tem da pomanjšamo energijo
                //std::cout<<"bounce "<<std::endl;
                // vel[0]=0;

            }


            if (iter%drawSparse==0||distsq(pos)>=r*r)
            {
                for (int i = 0; i < dim; i++)
                {
                    //    pos[i] += vel[i]*dt;
                    fprintf(pisi,"%lf \t ",pos[i]);


                }
                fprintf(pisi,"%lf \t ",energy(pos,vel));

                fprintf(pisi,"\n ");
            }


            iter++;


        }
        fclose(pisi);
        dt/=factor;
        maks*=factor;


    }

}
void timetrapBAD(int factor, int depth)
{
    for (int i=0; i<depth; i++)
    {

        cout<<Emin<<endl;
        // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
        //y  x
        double pos[]={0,0.1};
        double vel[]={0,0};
        double E=0;
       // string fil= "pos.txt";
        FILE* pisi;
        pisi = fopen("Ineeddalongstingb.txt"+i,"w");
        int iter=0;

        while (energy(pos,vel)>Emin&&iter<maks)
        {
            //cout<<distsq(pos)<<endl;
            //cout<<pos[0]*pos[1]<<endl;



            for (int i = 0; i < dim; i++)
            {
                pos[i] += vel[i]*dt;
                //          fprintf(pisi,"%lf \t ",pos[i]);


            }
            vel[0] += g*dt;

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
                times(-(2)*scale,pos,mideruslt);//verjetno izgubi samo radialno hitrost
                add(vel,mideruslt);
                times(sqrt(ke),vel,vel);//pomnožimo s tem da pomanjšamo energijo
                //std::cout<<"bounce "<<std::endl;
                // vel[0]=0;

            }


            if (iter%drawSparse==0||distsq(pos)>=r*r)
            {
                for (int i = 0; i < dim; i++)
                {
                    //    pos[i] += vel[i]*dt;
                    fprintf(pisi,"%lf \t ",pos[i]);


                }
                fprintf(pisi,"%lf \t ",energy(pos,vel));

                fprintf(pisi,"\n ");
            }


            iter++;


        }
        fclose(pisi);
        dt/=factor;
        maks*=factor;


    }

}






int main()
{
    //pipe();
    //pipeBAD();
    timetrap(10,3);
   // timetrapBAD(10,3);


 //   cout<<drawSparse<<endl;

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}