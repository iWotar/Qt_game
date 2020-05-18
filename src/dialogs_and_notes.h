#ifndef DIALOGS_AND_NOTES_H
#define DIALOGS_AND_NOTES_H

#include <QMap>

enum class NoteType {
    NONE,
    BEGINNING,
    PLAN,
    GIRL,
    HUNTER,
    CLOISTRESS,  // монахиня
    HEAD_DAUGHTER,
    STRONGBOX,  // сейф
    HEAD,  // староста
    PRIEST,  // священник
    TABLE
};

// разделил на диалоги, происходящие в разное время
enum class DialogType {
  NONE,
  HIRELING,  // наёмник
  HEAD,
  GETTING_UP,
  FOOD,
  WATER,
  OBSTRUCTION  // завал
};

class DialogsAndNotes {
 public:
  DialogsAndNotes();

  QString ShowText(NoteType type);
  QString ShowText(DialogType type);

 private:
  QMap<NoteType, QStringList> notes_;
  QMap<NoteType, bool> is_read_;
  NoteType current_note_;
  int current_list_;

  QMap<DialogType, QStringList> dialogs_;
  DialogType current_dialog_;
  int current_phrase_;
};

#endif  // DIALOGS_AND_NOTES_H
