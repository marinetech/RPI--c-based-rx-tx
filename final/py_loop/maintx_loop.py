from time import sleep
from helper import reset
from helper import runCMD
from os import path
from os import listdir
from os import makedirs
import signal
import fcntl
import os
# ======  Variables ==============

Fs = 250000
rxFilename = 'File2Rx_'
refFileName = 'ShortLFM'
FNAME = "./tx"
c = {}

modems = ['136']
c['136'] = ['1','0','0'] # threshold 1-4095 , gain , level
c['137'] = ['200','0','0']
c['138'] = ['1','0','0']
c['149'] = ['1','0','0']
c['147'] = ['1','0','0']
c['148'] = ['1','0','0']

# ============== loop code ============

def handler(signum, frame):
    print ('./tx was changed')
    runCMD('stop',modems[0])
    for n in os.listdir(FNAME):
        runCMD('tx ' + FNAME + '/' + n,modems[0])
        os.remove(FNAME + '/' + n)
    notify(FNAME, handler)

def notify(directory, handler):
    fd = os.open(FNAME, os.O_RDONLY)
    fcntl.fcntl(fd, fcntl.F_NOTIFY,fcntl.DN_CREATE)
    signal.signal(signal.SIGIO, handler)

if not path.exists(FNAME):
    makedirs(FNAME)

if not path.exists('./tmp'):
    makedirs('./tmp')

notify(FNAME, handler)

m = modems[0]
try:
    reset('192.168.0.' + m)
except:
    print("# Cannot connect to modem : " + m )
    exit()

runCMD('stop',m)


while 1:
	nextFileId =  len([name for name in listdir('./tmp') if (path.isfile('./tmp/' + name) and rxFilename in './tmp/' + name)])
	print("# of file : " + str(nextFileId) )
	runCMD('config 100 0 0\n',m)
	runCMD('ref tmp/' + refFileName,m)
	runCMD('rx ' + str(Fs*1) + ' ./tmp/' + rxFilename + str(nextFileId),m)
