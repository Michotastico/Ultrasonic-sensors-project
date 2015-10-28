


% Real time plotting.








clear all
close all
clc
 

arduino=serial('COM4','BaudRate',9600); %5aly balak mn el baud rate w el COM number % create serial communication object on port COM18
fopen(arduino); % initiate arduino communication

CM(1)=0;
time(1)=0;
i=1;
tic;


while (toc<=20)
   
   CM(2)=fscanf(arduino,'%f');
   time(2)=toc;
   figure(1);
   grid on;
   axis([toc-10, toc+10, 0, 400])
   h(i)=plot(time,CM,'b','LineWidth',4);
   hold on
   CM(1)=CM(2);
   time(1)=time(2);
 if(i >= 300)
   delete(h(i-299));
   end
i=i+1;
 % ew3a t7oot pause w 5aly el delay fee el arduino msh aktar mn 50
   % milliseconds
end
 
fclose(arduino); % end communication with arduino