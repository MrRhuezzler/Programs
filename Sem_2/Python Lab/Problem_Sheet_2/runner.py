from pprint import pp, pprint
import os

toBeRun = []
languagesInfo = {
    '.py' : {
        'language' : 'python',
        'command' : 'python #FILE#.py > temp.out < temp.in',
    },
    '.cpp' : {
        'language' : 'cpp',
        'command' : 'g++ #FILE#.cpp > temp.out < temp.in',
    }, 
    '.c' : {
        'language' : 'c',
        'command' : 'gcc #FILE#.c > temp.out < temp.in',
    }
}

for root, dirs, files in os.walk(os.getcwd()):
    for file in files:
        filename, ext = os.path.splitext(file)
        
        Info = languagesInfo.get(ext, None)
        if Info and (file != __file__):
            FileInfo = {}
            FileInfo['language'] = Info['language']
            FileInfo['filename'] = filename
            FileInfo['ext'] = ext
            FileInfo['content'] = open(file).readlines()
            FileInfo['inputFile'] = f'{filename}.in'
            FileInfo['outputFile'] = f'{filename}.out'
            FileInfo['command'] = Info['command'].replace("#FILE#", filename)

            toBeRun.append(FileInfo)


