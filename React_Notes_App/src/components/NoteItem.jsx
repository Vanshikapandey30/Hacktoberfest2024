import React from "react";

const NoteItem = ({ note, onDelete, onEdit }) => {
  return (
    <div className="note-item">
      <p>{note.text}</p>
      <div>
        <button onClick={() => onEdit(note)}>Edit</button>
        <button onClick={() => onDelete(note.id)}>Delete</button>
      </div>
    </div>
  );
};

export default NoteItem;
