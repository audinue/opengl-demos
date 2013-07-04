#include <QGuiApplication>
#include <QSurfaceFormat>

#include "specularmapscene.h"
#include "window.h"

int main( int argc, char* argv[] )
{
    QGuiApplication a( argc, argv );

    // Specify the format we wish to use
    QSurfaceFormat format;
    format.setMajorVersion( 3 );
#if !defined(Q_OS_MAC)
    format.setMinorVersion( 3 );
#else
    format.setMinorVersion( 2 );
#endif
    format.setDepthBufferSize( 24 );
    format.setSamples( 8 );
    format.setProfile( QSurfaceFormat::CoreProfile );

    Window w( format );
    w.setScene( new SpecularMapScene );

    w.show();
    return a.exec();
}
