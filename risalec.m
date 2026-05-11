 drawer= load("/home/doominik/securityCopy/FAX/NumerikaProjekt/cmake-build-debug/pos.txt")
 figure(1)
 comet(drawer(:,2),-drawer(:,1));
 figure(2)
 plot(sqrt(drawer(:,1).^2+drawer(:,2).^2))
 figure(3)
 plot(drawer(:,3))

