// CommandProcessor.cpp
//
// ICS 45C Fall 2014
// Project #4: People Just Love to Play with Words
//
// Implementation of the CommandProcessor class

#include "CommandProcessor.hpp"
#include "EditorException.hpp"
#include "Keypress.hpp"


CommandProcessor::CommandProcessor(Editor& editor, EditorView& view)
    : editor{editor}, view{view}
{
}


namespace
{
    // An "enum class" defines a type that has one of the constant values
    // specified.  So, in this case, a variable of type UserInteractionType
    // could have the value UserInteractionType::command,
    // UserInteractionType::undo, etc.
    enum class UserInteractionType
    {
        command,
        undo,
        redo,
        quit
    };


    // A UserInteraction describes one interaction that the user undertakes
    // with BooEdit.  There are four different kinds of interactions:
    //
    // * Commands, which attempt to affect some kind of change on the editor
    // * Undo, which asks for the previous change to be undone
    // * Redo, which asks for the most-recently undone change to be redone
    // * Quit, which asks for the editor to be stopped altogether
    //
    // A Command* is included for the case where UserInteractionType::command
    // is the specified type; otherwise, it will be nullptr.
    struct UserInteraction
    {
        UserInteractionType type;
        Command* command;
    };


/*
    // You'll want these three functions, but I'm commenting them out for now,
    // so that this will compile without warnings.

    UserInteraction makeCommandInteraction(Command* command)
    {
        return UserInteraction{UserInteractionType::command, command};
    }


    UserInteraction makeUndoInteraction()
    {
        return UserInteraction{UserInteractionType::undo, nullptr};
    }


    UserInteraction makeRedoInteraction()
    {
        return UserInteraction{UserInteractionType::redo, nullptr};
    }
*/

    
    UserInteraction makeQuitInteraction()
    {
        return UserInteraction{UserInteractionType::quit, nullptr};
    }


    // You will need to update this function to watch for the right keypresses
    // and build the right kinds of user interactions.  I've added handling
    // for "quit" here, but you'll need to add the others.
    UserInteraction nextUserInteraction()
    {
        while (true)
        {
            Keypress keypress = nextKeypress();

            if (keypress.ctrl)
            {
                // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly

                switch (keypress.c)
                {
                case 'X':
                    return makeQuitInteraction();
                }
            }
            else
            {
                // The user pressed a normal key (e.g., 'h') without holding
                // down Ctrl; react accordingly
                
                //-------------------------------------
                // COMMAND IS ADDED HERE
                //-------------------------------------


            }
        }
    }
}


// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.

void CommandProcessor::run()
{
    view.refresh();

    while (true)
    {
        UserInteraction interaction = nextUserInteraction();

        if (interaction.type == UserInteractionType::quit)
        {
            break;
        }
        else if (interaction.type == UserInteractionType::undo)
        {
        }
        else if (interaction.type == UserInteractionType::redo)
        {
        }
        else if (interaction.type == UserInteractionType::command)
        {
            try
            {
                interaction.command->execute(editor);
                view.clearErrorMessage();
            }
            catch (EditorException& e)
            {
                view.showErrorMessage(e.getReason());
            }

            view.refresh();

            // Note that you'll want to be more careful about when you delete
            // commands once you implement undo and redo.  For now, since
            // neither is implemented, I've just deleted it immediately
            // after executing it.  You'll need to wait to delete it until
            // you don't need it anymore.
            delete interaction.command;
        }
    }
}

