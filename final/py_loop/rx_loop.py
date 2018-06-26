from time import sleep
from helper import reset
from helper import runCMD
from os import listdir
from os import path

#Fs = 67500
Fs = 250000
c = {}

WinLen = 4;
rxFilename = 'File2Rx_'
refFileName = 'ShortLFM'

############################
####   Variables    ########
############################

modems = ['136']
c['136'] = ['1','0','0'] # threshold 1-4095 , gain , level
c['137'] = ['200','0','0'] 
c['138'] = ['1','0','0'] 
c['146'] = ['1','0','0'] 
c['147'] = ['1','0','0'] 
c['148'] = ['1','0','0'] 

############################
#### Run the script ########
############################

# commands : 
# stop 
# config Threshold, gain, level
# tx [filename]
# tx ShortLFM
# tx LFM
# ref [filename]
# rx [samples] tmp/[filename]


for m in modems:
	try:
		reset('192.168.0.' + m)
	except:
		print("# Cannot connect to modem : " + m )
		continue
	runCMD('config ' + ' '.join(c[m]) + '\n',m)	
	runCMD('ref tmp/' + refFileName,m)
	#runCMD('rx ' + str(Fs*4) + ' tmp/rx_OFDM_Second',m)

while 1:
	nextFileId =  len([name for name in listdir('./tmp') if (path.isfile('./tmp/' + name) and rxFilename in './tmp/' + name)])
	print("# of file : " + str(nextFileId) )
	runCMD('rx ' + str(Fs*WinLen) + ' ./tmp/' + rxFilename + str(nextFileId),m)


#for m in modems:
	#try:
		#reset('192.168.0.' + m)
	#except:
		#print("# Cannot connect to modem : " + m )
		#continue
	#runCMD('config ' + ' '.join(c[m]) + '\n',m)
	#runCMD('tx tmp/ShortLFM',m)
	#sleep(0.25)
	#runCMD('tx tmp/LFM',m)
	#sleep(1)
	#runCMD('tx tmp/ShortLFM',m)
	#runCMD('tx tmp/ShortLFM',m)
	#runCMD('ref tmp/ShortLFM',m)
	#runCMD('rx 125000 tmp/rx1',m)
	#sleep(1)
