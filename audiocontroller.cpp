#include "audiocontroller.h"
#include <QUrl>

AudioController::AudioController(QObject *parent)
    : QObject(parent)
    , m_fadeSpeed(0.5)
    , m_loopOverlap(1.0)
{
    // Initialize 12 players
    for (int i = 0; i < 12; ++i) {
        initializePlayer(i);
    }
}

void AudioController::initializePlayer(int index)
{
    ChordPlayer player;
    player.player = std::make_unique<QMediaPlayer>();
    player.output = std::make_unique<QAudioOutput>();
    player.isPlaying = false;

    player.player->setAudioOutput(player.output.get());
    // Set the source file - you'll need to replace this with actual audio files
    player.player->setSource(QUrl::fromLocalFile(QString("chord_%1.wav").arg(index + 1)));
    player.player->setLoops(QMediaPlayer::Infinite);
    
    m_players[index] = std::move(player);
}

void AudioController::playChord(int index)
{
    if (auto it = m_players.find(index); it != m_players.end()) {
        it->output->setVolume(1.0);
        it->player->play();
        it->isPlaying = true;
    }
}

void AudioController::stopChord(int index)
{
    if (auto it = m_players.find(index); it != m_players.end()) {
        it->player->stop();
        it->isPlaying = false;
    }
}

void AudioController::setFadeSpeed(double speed)
{
    m_fadeSpeed = speed;
}

void AudioController::setLoopOverlap(double overlap)
{
    m_loopOverlap = overlap;
} 