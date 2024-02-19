@echo off
git add *
echo "Enter branch to commit to: "
set /p branchType=""
echo "Enter commit message: "
set /p commitMessage=""
@echo on
git commit -%branchType% "%commitMessage%"
git push origin
pause