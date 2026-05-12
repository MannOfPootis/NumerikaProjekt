 drawer= load("/home/doominik/securityCopy/FAX/NumerikaProjekt/cmake-build-debug/pos.txt")
 figure(1)
 plot(drawer(:,2),-drawer(:,1));
 title("trajektorija delca")
 drawnow
 %saveas(gcf,"/home/doominik/securityCopy/FAX/NumerikaProjekt/sutraj.jpg")
 figure(2)

 %{
 subplot(2,1,2);
 plot(sqrt(drawer(:,1).^2+drawer(:,2).^2))
title("razdalja od sredine")
  subplot(2,1,1);
%}

 plot(drawer(:,3))
   title("skupna mehanska energija")
   drawnow
 %saveas(gcf,"/home/doominik/securityCopy/FAX/NumerikaProjekt/susE.jpg")


