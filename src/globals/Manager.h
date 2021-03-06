#pragma once

#include "concerts/ConcertFileSearcher.h"
#include "concerts/ConcertModel.h"
#include "data/Database.h"
#include "media_centers/MediaCenterInterface.h"
#include "movies/MovieFileSearcher.h"
#include "movies/MovieModel.h"
#include "music/MusicFileSearcher.h"
#include "music/MusicModel.h"
#include "scrapers/concert/ConcertScraperInterface.h"
#include "scrapers/image/FanartTv.h"
#include "scrapers/image/ImageProviderInterface.h"
#include "scrapers/movie/MovieScraperInterface.h"
#include "scrapers/music/MusicScraperInterface.h"
#include "scrapers/music/TvTunes.h"
#include "scrapers/trailer/TrailerProvider.h"
#include "scrapers/tv_show/TvScraperInterface.h"
#include "settings/Settings.h"
#include "tv_shows/TvShowFileSearcher.h"
#include "tv_shows/TvShowModel.h"
#include "tv_shows/TvShowProxyModel.h"
#include "ui/main/FileScannerDialog.h"
#include "ui/main/MyIconFont.h"
#include "ui/music/MusicFilesWidget.h"
#include "ui/tv_show/TvShowFilesWidget.h"

#include <QString>
#include <QVector>

class MediaCenterInterface;

/**
 * @brief The Manager class
 * This class handles the various interfaces
 */
class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject* parent = nullptr);
    ~Manager() override;

    static Manager* instance();
    QVector<MediaCenterInterface*> mediaCenters();
    QVector<MovieScraperInterface*> movieScrapers();
    MovieScraperInterface* scraper(const QString& identifier);
    QVector<TvScraperInterface*> tvScrapers();
    QVector<ConcertScraperInterface*> concertScrapers();
    QVector<MusicScraperInterface*> musicScrapers();
    QVector<ImageProviderInterface*> imageProviders();
    QVector<ImageProviderInterface*> imageProviders(ImageType type);
    QVector<TrailerProvider*> trailerProviders();
    MediaCenterInterface* mediaCenterInterface();
    MediaCenterInterface* mediaCenterInterfaceTvShow();
    MediaCenterInterface* mediaCenterInterfaceConcert();
    MovieFileSearcher* movieFileSearcher();
    TvShowFileSearcher* tvShowFileSearcher();
    ConcertFileSearcher* concertFileSearcher();
    MusicFileSearcher* musicFileSearcher();
    Database* database();
    MovieModel* movieModel();
    TvShowModel* tvShowModel();
    ConcertModel* concertModel();
    MusicModel* musicModel();
    FileScannerDialog* fileScannerDialog();
    FanartTv* fanartTv();
    TvShowFilesWidget* tvShowFilesWidget();
    MusicFilesWidget* musicFilesWidget();
    TvTunes* tvTunes();
    MyIconFont* iconFont();
    void setTvShowFilesWidget(TvShowFilesWidget* widget);
    void setMusicFilesWidget(MusicFilesWidget* widget);
    void setFileScannerDialog(FileScannerDialog* dialog);
    static QVector<MovieScraperInterface*> constructNativeScrapers(QObject* parent);

private:
    QVector<MediaCenterInterface*> m_mediaCenters;
    QVector<MediaCenterInterface*> m_mediaCentersTvShow;
    QVector<MediaCenterInterface*> m_mediaCentersConcert;
    QVector<MovieScraperInterface*> m_scrapers;
    QVector<TvScraperInterface*> m_tvScrapers;
    QVector<ConcertScraperInterface*> m_concertScrapers;
    QVector<MusicScraperInterface*> m_musicScrapers;
    QVector<ImageProviderInterface*> m_imageProviders;
    QVector<TrailerProvider*> m_trailerProviders;
    MovieFileSearcher* m_movieFileSearcher;
    TvShowFileSearcher* m_tvShowFileSearcher;
    ConcertFileSearcher* m_concertFileSearcher;
    MovieModel* m_movieModel;
    TvShowModel* m_tvShowModel;
    ConcertModel* m_concertModel;
    MusicModel* m_musicModel;
    Settings* m_settings;
    Database* m_database;
    TvShowFilesWidget* m_tvShowFilesWidget;
    MusicFilesWidget* m_musicFilesWidget;
    FileScannerDialog* m_fileScannerDialog;
    TvTunes* m_tvTunes;
    MusicFileSearcher* m_musicFileSearcher;
    MyIconFont* m_iconFont;
};
