import React, { useState, useEffect } from "react";

const NoteForm = ({ onSubmit, noteToEdit }) => {
  const [note, setNote] = useState(noteToEdit ? noteToEdit.text : "");

  useEffect(() => {
    if (noteToEdit) setNote(noteToEdit.text);
  }, [noteToEdit]);

  const handleSubmit = (e) => {
    e.preventDefault();
    if (note.trim()) {
      onSubmit(note);
      setNote("");
    }
  };

  return (
    <form onSubmit={handleSubmit} className="note-form">
      <input
        type="text"
        placeholder="Enter a note"
        value={note}
        onChange={(e) => setNote(e.target.value)}
      />
      <button type="submit">{noteToEdit ? "Update Note" : "Add Note"}</button>
    </form>
  );
};

export default NoteForm;
