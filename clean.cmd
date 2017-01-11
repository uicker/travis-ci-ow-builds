"C:\Program Files (x86)\SmartGit\git\bin\git" pull
"C:\Program Files (x86)\SmartGit\git\bin\git" checkout --orphan temp1
"C:\Program Files (x86)\SmartGit\git\bin\git" add -A
"C:\Program Files (x86)\SmartGit\git\bin\git" commit -am "Initial commit"
"C:\Program Files (x86)\SmartGit\git\bin\git" branch -D master
"C:\Program Files (x86)\SmartGit\git\bin\git" branch -m master
"C:\Program Files (x86)\SmartGit\git\bin\git" push -f origin master
"C:\Program Files (x86)\SmartGit\git\bin\git" branch --set-upstream-to=origin/master master
