#ifndef AUDIOCONTROLLER_H
#define AUDIOCONTROLLER_H

#include <QObject>
#include <QMap>
#include <QAudioOutput>
#include <QMediaPlayer>
#include <memory>

class AudioController : public QObject
{
    Q_OBJECT

public:
    explicit AudioController(QObject *parent = nullptr);

public slots:
    void playChord(int index);
    void stopChord(int index);
    void setFadeSpeed(double speed);
    void setLoopOverlap(double overlap);

private:
    struct ChordPlayer {
        std::unique_ptr<QMediaPlayer> player;
        std::unique_ptr<QAudioOutput> output;
        bool isPlaying;
    };

    QMap<int, ChordPlayer> m_players;
    double m_fadeSpeed;
    double m_loopOverlap;

    void initializePlayer(int index);
};

#endif // AUDIOCONTROLLER_H 