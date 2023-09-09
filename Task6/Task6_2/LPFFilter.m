% Define signal parameters
samplingFreq = 1000;  % Sampling frequency in Hz
t = 0:1/samplingFreq:1;  % Time of signal
sigFreq = 5;  % Frequency of the rectangular wave in Hz
sigAmp = 1;

% Create input signal of rotaryEncoder
signal = sigAmp * square(2 * pi * sigFreq * t);

% Add noise
noise_amplitude = 0.5;
noise = noise_amplitude * randn(size(t));
noisy_signal = signal + noise;
noisy_signal_f=abs(fftshift(fft(noisy_signal)));
fvec=linspace(-samplingFreq/2, samplingFreq/2, length(noisy_signal_f));

figure;
subplot(2,2,2);
plot(fvec, noisy_signal_f);
title('Noisy signal in Frequency Domain');
xlabel('Frequency');
ylabel('Amplitude');

% Plot the noisy signal
subplot(2,2,1);
plot(t, noisy_signal);
title('Noisy signal in time domain');
xlabel('Time');
ylabel('Amplitude');
% Define LPF parameters
                                                     % (540*0.5)/2pi*40*10^-2
cutoff_frequency = 80;  % Cutoff frequency in HZ ((SpeedxPulseperRevolution)/(2Pi*raduis))*75%
filter_order = 1;

% Calculate the normalized cutoff frequency
nyquist_frequency = 0.5 * samplingFreq;
normalized_cutoff_frequency = cutoff_frequency / nyquist_frequency;

% Design the Butterworth LPF
[b, a] = butter(filter_order, normalized_cutoff_frequency, 'low');

% Apply the LPF to the noisy signal
filtered_signal = filter(b, a, noisy_signal);
filtered_signal_f=abs(fftshift(fft(filtered_signal)));
% Plot the filtered signal
subplot(2,2,3);
plot(t, filtered_signal);
title('Filtered signal in time domain');
xlabel('Time');
ylabel('Amplitude');

subplot(2,2,4);
plot(fvec, filtered_signal_f);
title('Filtered signal in time domain');
xlabel('Frequency');
ylabel('Amplitude');

