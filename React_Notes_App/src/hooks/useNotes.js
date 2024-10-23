import { useState } from "react";
import { v4 as uuidv4 } from "uuid";

const useNotes = () => {
  const [notes, setNotes] = useState([]);
  const [noteToEdit, setNoteToEdit] = useState(null);

  const addNote = (text) => {
    setNotes([...notes, { id: uuidv4(), text }]);
  };

  const deleteNote = (id) => {
    setNotes(notes.filter((note) => note.id !== id));
  };

  const editNote = (note) => {
    setNoteToEdit(note);
  };

  const updateNote = (text) => {
    setNotes(
      notes.map((note) =>
        note.id === noteToEdit.id ? { ...note, text } : note
      )
    );
    setNoteToEdit(null);
  };

  return { notes, addNote, deleteNote, editNote, updateNote, noteToEdit };
};

export default useNotes;
