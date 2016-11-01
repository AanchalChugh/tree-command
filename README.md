# tree-command
TITLE : tree command
NAME: Aanchal Chugh MIS NO. 111510001
It lists all files and directories present inside a particular directory, recursively accessing directories. 
Options implemented are:
-a Displays all files including those beginning with '.'
-f Displays full pathprefix for eac file
-d List only directories
-i List contents without indentation
--prune Excludes empty directories from tree
--noreport Omits printing no. of files and directories report at the end of tree
-o filename Instead of printing on screen prints tree in file
-L level prints tree only upto a specified level
--timefmt format depending on %c %x format displays tree along with last modified date and time of directory and file.
--filelimit # Opens directory only when it contains less than # entries.
Also different combinations of options like -f -i -o filename, -f -d -L level, -i -d --noreport works.
