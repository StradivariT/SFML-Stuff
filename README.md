## SFML Stuff

Trying to extrapolate the [Coding Math](https://www.youtube.com/watch?v=zm9bqSSiIdo&list=PL7wAPgl1JVvUEb0dIygHzO4698tmcwLk9&ab_channel=CodingMath) playlist from Javascript to C++. This repo uses the [SFML VSCode Boilerplate](https://github.com/andrew-r-king/sfml-vscode-boilerplate) to generate new projects.


### Usage
* Create a new project

To create a new project, just copy and paste the `boilerplate` folder replacing its name with how the new project will be named. After this, open the new project on vscode

* Run a project

On vscode, type `Command + Shift + B` and select `Build and Run: Debug`, or any other task that suits your needs. 
If this doesn't work at first due to `filesystem` header not being found, try running `bash ./build.sh buildrun Debug vscode` first


Remember that you needed to do `brew install llvm` and modify your `zshrc` file first on Mojave