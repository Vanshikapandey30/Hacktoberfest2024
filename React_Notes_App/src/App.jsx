import React from "react";
import NoteForm from "./components/NoteForm";
import NoteList from "./components/NoteList";
import useNotes from "./hooks/useNotes";
import "./styles/App.css";

const App = () => {
  const { notes, addNote, deleteNote, editNote, updateNote, noteToEdit } =
    useNotes();

  return (
    <div className="App">
      <h1>Notes App</h1>
      <NoteForm
        onSubmit={noteToEdit ? updateNote : addNote}
        noteToEdit={noteToEdit}
      />
      <NoteList notes={notes} onDelete={deleteNote} onEdit={editNote} />
    </div>
  );
};

export default App;
