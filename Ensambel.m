
drawer1= load("/home/doominik/securityCopy/FAX/NumerikaProjekt/cmake-build-debug/Ineeddalongsting.txt");
drawer2= load("/home/doominik/securityCopy/FAX/NumerikaProjekt/cmake-build-debug/needdalongsting.txt");
drawer3= load("/home/doominik/securityCopy/FAX/NumerikaProjekt/cmake-build-debug/eeddalongsting.txt");
drawer1b= load("/home/doominik/securityCopy/FAX/NumerikaProjekt/cmake-build-debug/Ineeddalongstingb.txt");
drawer2b= load("/home/doominik/securityCopy/FAX/NumerikaProjekt/cmake-build-debug/needdalongstingb.txt");
drawer3b= load("/home/doominik/securityCopy/FAX/NumerikaProjekt/cmake-build-debug/eeddalongstingb.txt");


best= load("/home/doominik/securityCopy/FAX/NumerikaProjekt/cmake-build-debug/pos.txt");
bestBAD= load("/home/doominik/securityCopy/FAX/NumerikaProjekt/cmake-build-debug/posBAD.txt");
lent = 10000;
drawer1(end+1:lent,:)=0;
drawer2(end+1:lent,:)=0;
drawer3(end+1:lent,:)=0;
filename = '/home/doominik/securityCopy/FAX/NumerikaProjekt/cmake-build-debug/lookatfunny2.gif';
DelayTime = 0.05;
drawing=1

f=figure


fi= linspace(0,pi,100);
%axis ([-1, 1, -1,1 ]);

for dex= 1:lent
  hold off
  scatter(drawer1(dex,2),-drawer1(dex,1));
  hold on
  plot(cos(fi),-sin(fi))
  for hex = 1:10
    mex= (10*dex)-10+hex;
    scatter(drawer2(mex,2),-drawer2(mex,1),"r");
    scatter(drawer3(mex,2),-drawer3(mex,1),"g");
    legend("dt=0.1","rob","dt=0.01", "dt=0.001");

    if(drawing==1)
    drawnow

    % Image Processing
    % Assign plot to a frame
    frame = getframe(f);
    % Convert frame to RGB image (3 dimensional)
    im = frame2im(frame);
    % Transform RGB samples to 1 dimension with a color map "cm".
    [imind,cm] = rgb2ind(im);
    if and(dex == 1,mex==1);
      % Create GIF file
      imwrite(imind,cm,filename,'gif','DelayTime', DelayTime , 'Compression' , 'lzw');
    else
      % Add each new plot to GIF
      imwrite(imind,cm,filename,'gif','WriteMode','append','DelayTime', DelayTime , 'Compression' , 'lzw');
    end
  end

  %pause(0.1)
end

%%axis ([-1, 1, -1,1 ]);

pause(1);
end
%{
figure(1)

plot(drawer1(:,2),-drawer1(:,1));
hold on
plot(drawer2(:,2),-drawer2(:,1));
plot(drawer3(:,2),-drawer3(:,1));


hold off
title("trajektorija delca")
legend("dt=0.1", "dt= 0.001", "dt = 0.00001")

drawnow
%}
%saveas(gcf,"/home/doominik/securityCopy/FAX/NumerikaProjekt/sutraj.jpg")
figure(2)

%{
subplot(2,1,2);
plot(sqrt(drawer(:,1).^2+drawer(:,2).^2))
title("razdalja od sredine")
subplot(2,1,1);
%}




lenbest=length(best);
%{
len1= length(drawer1)
len2= length(drawer2)
len3= length(drawer3)
len1b= length(drawer1b)
len2b= length(drawer2b)
len3b= length(drawer3b)
dt1= zeros(len1,1)+1
dt2=zeros(len2,1)+2
dt3=zeros(len3,1)+3
dt1b= zeros(len1b,1)+1
dt2b= zeros(len2b,1)+2
dt3b= zeros(len3b,1)+3

plot3(dt1,(1:len1)*10,drawer1(:,3))
hold on

plot3(dt2,(1:len2),drawer2(:,3))
plot3(dt3,(1:len3),drawer3(:,3))
plot3(dt1b,(1:len1b),drawer1b(:,3))
plot3(dt2b,(1:len2b),drawer2b(:,3))
plot3(dt3b,(1:len3b),drawer3b(:,3))
%plot()
hold off

%}


%{
plot(1:lenbest,best(:,3));
hold on
plot(bestBAD(:,3))
hold off
title("skupna mehanska energija pri dt = 0.001")
ylabel("energija(J)")
xlabel ("čas(s)")
legend( " v, r","r, v")
drawnow
saveas(gcf,"/home/doominik/securityCopy/FAX/NumerikaProjekt/errorEcring2.jpg")
%}


