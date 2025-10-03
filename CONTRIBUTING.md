# How to Contribute


- Fork this repository - [How to fork a repository](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/working-with-forks/fork-a-repo)
- Clone the forked repository into local space
- Choose any task on [Hackerrank](https://www.hackerrank.com/), [Codechef](https://www.codechef.com/) or any other online platform and solve it, (or choose your already solved question)
- Paste the solution code in new file and name it in following format:
PROBLEM_NAME.[Format of language used in your code]
(you should match it with the url, such that when a user type the url 
hackkerrank.com/challenges/PROBLEM_NAME/problem 
codechef.com/problems/PROBLEM_NAME
and so on
it will be redirected to the actual problem page)
- Place your source code file in respective folder (you can create a new folder if it is not present)
- Optional - You can add comments at the start of the file, if you want to share something, like steps to run the code etc
- Add and commit the changes. (Please do not make changes in any other file, but if you want to work on bug/improvement then add an issue first)
- Don't forget to add your name, image url, country and the language used in contributors table in the README.md file
- Generate a Pull Request (Optional: add problem name in the title and url to the problem in description)
- That's it, you have successfully completed your 1 out of 5 PRs. Well Done!


# How to Sync Forked Repo from Upstream Repo


1. Add the original repository as an upstream repository
```javascript
$ git remote add upstream https://github.com/[Original Owner Username]/[Original Repository].git
```
Hence, in this repository it would be
```javascript
$ git remote add upstream https://github.com/ows-ali/Hacktoberfest.git/
```

2. Fetch all the changes from the repository. Note that commits to the original repository will be stored in a local branch called, upstream/master
```javascript
$ git fetch upstream
```

3. Make sure that you are on your fork's master or working branch
```javascript
$ git checkout [working branch]
```
For example,
```javascript
$ git checkout master
```

4. Merge the changes from the upstream/master into  your local master or working branch. This will sync the fork's master branch with the upstream repository without losing your local changes. If you have made any changes that create conflict, you will have to resolve the conflict before you can complete the merge
```javascript
$ git merge upstream/master
```

5. At this point, your local branch is synced with the upstream/master branch. In order to update the remote branch in Github, you need to push your changes
```javascript
$ git push origin master
```
