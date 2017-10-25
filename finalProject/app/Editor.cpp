// Editor.cpp
//
// ICS 45C Fall 2014
// Project #4: People Just Love to Play with Words
//
// Implementation of the Editor class

#include "Editor.hpp"
#include "EditorException.hpp"


Editor::Editor()
{
}


int Editor::cursorLine() const
{
    return 1;
}


int Editor::cursorColumn() const
{
    return 1;
}


int Editor::lineCount() const
{
    return 1;
}


const std::string& Editor::line(int lineNumber) const
{
    static std::string removeThis = "BooEdit!";
    return removeThis;
}

