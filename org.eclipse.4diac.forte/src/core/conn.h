/*******************************************************************************
 * Copyright (c) 2005 - 2015 Profactor GmbH, ACIN, fortiss GmbH
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *    Thomas Strasser, Alois Zoitl, Gerhard Ebenhofer, Ingo Hegny,
 *    Michael Hofmann
 *      - initial implementation and rework communication infrastructure
 *******************************************************************************/
#ifndef _CONN_H_
#define _CONN_H_

#include <type_traits>

#include "fortelist.h"
#include "mgmcmd.h"
#include "stringdict.h"
#include "connectiondestinationtype.h"
#include <vector>

//forward declaration of a few classes to reduce include file dependencies
class CFunctionBlock;

class CConnectionPoint {
  public:
    CFunctionBlock *mFB;
    TPortId mPortId;

    CConnectionPoint(CFunctionBlock *paFB, TPortId paPortId) :
      mFB(paFB), mPortId(paPortId), mDestinationType(EConnectionDestinationType::e_IN) {
    }

    CConnectionPoint(CFunctionBlock *paFB, TPortId paPortId, EConnectionDestinationType paDestinationType) :
      mFB(paFB), mPortId(paPortId), mDestinationType(paDestinationType) {
    }

    CConnectionPoint() = default;

    bool operator==(const CConnectionPoint & paRight) const {
      return ((mFB == paRight.mFB) && (mPortId == paRight.mPortId) && (getConnectionDestinationType() == paRight.getConnectionDestinationType()));
    }

    bool operator!=(const CConnectionPoint & paRight) const {
      return !(*this == paRight);
    }

    EConnectionDestinationType getConnectionDestinationType() const {
      return mDestinationType;
    }

  private:
    EConnectionDestinationType mDestinationType;
};
static_assert(std::is_trivial_v<CConnectionPoint>);

/*!\ingroup CORE \brief Base class for handling a connection.
 */

class CConnection{
  public:

    using TDestinationIdList = std::vector<CConnectionPoint>;

    CConnection(CFunctionBlock *paSrcFB, TPortId paSrcPortId);

    virtual ~CConnection() = default;

    /*! \brief Establishes a connection.
     *
     * With this command the connection is created and the FBs are set to appropriate states.
     * As connections are stored at the function block outputs this mainly affects the destination of
     * the connection.
     *
     * A child needs to implement this function!
     *
     * \param paDstFB     the destination FB of this connection
     * \param paDestPortNameId the input port name to which this connection should be connected to
     * \return can be the following response:
     *     - Ready... creation went well.
     *     - NoSuchObject... The destination is not a valid input.
     *     - InvalidState... The specified connection already exists.
     */
    virtual EMGMResponse connect(CFunctionBlock *paDstFB,
        CStringDictionary::TStringId paDstPortNameId) = 0;

    /*!\brief establish an event connection of a CFB to an event output of the CFB.
     *
     */
    virtual EMGMResponse connectToCFBInterface(CFunctionBlock *paDstFB,
        CStringDictionary::TStringId paDstPortNameId) = 0;

    /*! \brief Disconnects the connection.
     *
     * With this command the connection is removed and the FBs are set to appropriate states.
     * This mainly effects the destination of the connection as the source point is the storage
     * for the connection object
     *
     * A child needs to implement this function!
     *
     * \param paDstFB     the destination FB of this connection
     * \param paDestPortNameId the input port name to from which this connection should be removed
     * \return can be the following response:
     *     - Ready... creation went well.
     *     - NoSuchObject... The destination is not a valid input.
     *     - InvalidState... this connection is not connected to the destination
     */
    virtual EMGMResponse disconnect(CFunctionBlock *paDstFB,
        CStringDictionary::TStringId paDstPortNameId) = 0;

    /*! \brief Check if there are destinations added to this connection
     *
     * \return TRUE if there is no destination in the connection.
     */
    bool isEmpty() const{
      return mDestinationIds.empty();
    }

    virtual bool isConnected() const{
      return !isEmpty();
    }

    /*! \brief Get the source string of the connection
     */
    const CConnectionPoint& getSourceId() const{
      return mSourceId;
    }

    /*! \brief Get list of destinations of the connection
     */
    const TDestinationIdList& getDestinationList() const {
        return mDestinationIds;
    }

  protected:
    EMGMResponse addDestination(const CConnectionPoint &paDestPoint);
    EMGMResponse removeDestination(const CConnectionPoint &paDestPoint);

    void setSource(CFunctionBlock *paSrcFB, TPortId paSrcPortId);

    //!Non const version
    CConnectionPoint& getSourceId(){
      return mSourceId;
    }

    /*!\brief a list of destinations the connection is connected to.
     *
     * By storing a list of destinations an implicit support for fan-out is given.
     * The destination is represented as string id the same way as the sourceId
     */
    TDestinationIdList mDestinationIds;

    /*!\brief An identifier for the source of this connection
     *
     * The source is identified by a FB pointer and the port ID
     */
    CConnectionPoint mSourceId;

  private:

    //! Check if there is already a connection within this connection with the same dst.
    bool dstExists(const CConnectionPoint& paDestPoint) const;
};

#endif /*_CONN_H_*/
