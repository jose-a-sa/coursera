t = [0:0.01:0.98]
y1 = sin(2*pi*4*t);
plot(t, y1);

pause(); close()

y2 = cos(2*pi*4*t)

hold on
plot(t, y1);
plot(t, y2, 'r');
xlabel('time')
ylabel('value')
legend('sin', 'cos')
title('my plot')

pause(); close()

figure(1)
plot(t, y1);
figure(2)
plot(t, y2, 'r');

pause(); close()
